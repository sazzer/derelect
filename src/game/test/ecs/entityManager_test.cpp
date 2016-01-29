#include "ecs/entityManager.hpp"
#include <set>
#include <iostream>
#include <bandit/bandit.h>
using namespace bandit;

go_bandit([](){
    describe("ECS::EntityManager", [&]() {
        class TestComponent : public ECS::Component {
        public:
            TestComponent() {
                std::cerr << "Constructing TestComponent" << std::endl;
            }
            virtual ~TestComponent() {
                std::cerr << "Destroying TestComponent" << std::endl;
            }
            virtual nameType name() const {
                return "TestComponent";
            }
        };

        it("Should generate different EntityIDs on consecutive calls", [&]() {
            std::set<ECS::EntityId> generatedIds;

            for (int i = 0; i < 10; ++i) {
                ECS::EntityId nextId = ECS::generateEntityId();
                AssertThat(generatedIds.count(nextId), Equals(0u));
                generatedIds.insert(nextId);
            }
        });
        it("Should have no components when just created", [&]() {
            ECS::EntityId entity = ECS::generateEntityId();
            AssertThat(ECS::getComponentNamesForEntity(entity), HasLength(0));
            AssertThat(ECS::entityHasComponent(entity, "TestComponent"), IsFalse());
        });
        it("Should have components when just added", [&]() {
            ECS::EntityId entity = ECS::generateEntityId();
            ECS::addComponentToEntity(entity, std::shared_ptr<TestComponent>(new TestComponent()));

            auto componentNames = ECS::getComponentNamesForEntity(entity);
            AssertThat(componentNames, HasLength(1));
            AssertThat(componentNames, Has().Exactly(1).EqualTo("TestComponent"));

            AssertThat(ECS::entityHasComponent(entity, "TestComponent"), IsTrue());
        });
        it("Should not have components when just removed", [&]() {
            ECS::EntityId entity = ECS::generateEntityId();
            ECS::addComponentToEntity(entity, std::shared_ptr<TestComponent>(new TestComponent()));
            ECS::removeComponentFromEntity(entity, "TestComponent");

            auto componentNames = ECS::getComponentNamesForEntity(entity);
            AssertThat(ECS::getComponentNamesForEntity(entity), HasLength(0));
            AssertThat(ECS::entityHasComponent(entity, "TestComponent"), IsFalse());
        });
    });
});
