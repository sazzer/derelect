#include "ecs/entityManager.hpp"
#include <set>
#include <bandit/bandit.h>
using namespace bandit;

go_bandit([](){
    describe("ECS::EntityManager", [&]() {
        it("Should generate different EntityIDs on consecutive calls", [&]() {
            std::set<ECS::EntityId> generatedIds;

            for (int i = 0; i < 10; ++i) {
                ECS::EntityId nextId = ECS::generateEntityId();
                AssertThat(generatedIds.count(nextId), Equals(0u));
                generatedIds.insert(nextId);
            }
        });
    });
});
