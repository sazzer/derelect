#include "ecs/entityId.hpp"
#include <sstream>
#include <bandit/bandit.h>
using namespace bandit;

go_bandit([](){
    describe("ECS::EntityId", [&]() {
        it("Should return the ID it was constructed with", [&]() {
            uint64_t id = 1234;
            ECS::EntityId entityId(id);
            AssertThat(entityId.id(), Equals(id));
        });
        it("Should copy correctly", [&]() {
            uint64_t id = 1234;
            ECS::EntityId entityId(id);
            ECS::EntityId entityId2(entityId);
            AssertThat(entityId2.id(), Equals(id));
        });
        it("Should copy-assign correctly", [&]() {
            uint64_t id = 1234;
            ECS::EntityId entityId(id);
            ECS::EntityId entityId2 = entityId;
            AssertThat(entityId2.id(), Equals(id));
        });
        it("Should compare as Equal correctly", [&]() {
            ECS::EntityId entityId(1234);
            ECS::EntityId entityId2(1234);
            ECS::EntityId entityId3(4321);
            AssertThat(entityId == entityId3, IsFalse()); //Less Than
            AssertThat(entityId == entityId2, IsTrue()); //Equal
            AssertThat(entityId3 == entityId, IsFalse()); //Greater Than
        });
        it("Should compare as Not Equal correctly", [&]() {
            ECS::EntityId entityId(1234);
            ECS::EntityId entityId2(1234);
            ECS::EntityId entityId3(4321);
            AssertThat(entityId != entityId3, IsTrue()); //Less Than
            AssertThat(entityId != entityId2, IsFalse()); //Equal
            AssertThat(entityId3 != entityId, IsTrue()); //Greater Than
        });
        it("Should compare as Less Than correctly", [&]() {
            ECS::EntityId entityId(1234);
            ECS::EntityId entityId2(1234);
            ECS::EntityId entityId3(4321);
            AssertThat(entityId < entityId3, IsTrue()); //Less Than
            AssertThat(entityId < entityId2, IsFalse()); //Equal
            AssertThat(entityId3 < entityId, IsFalse()); //Greater Than
        });
        it("Should compare as Greater Than correctly", [&]() {
            ECS::EntityId entityId(1234);
            ECS::EntityId entityId2(1234);
            ECS::EntityId entityId3(4321);
            AssertThat(entityId > entityId3, IsFalse()); //Less Than
            AssertThat(entityId > entityId2, IsFalse()); //Equal
            AssertThat(entityId3 > entityId, IsTrue()); //Greater Than
        });
        it("Should compare as Less Than Or Equal correctly", [&]() {
            ECS::EntityId entityId(1234);
            ECS::EntityId entityId2(1234);
            ECS::EntityId entityId3(4321);
            AssertThat(entityId <= entityId3, IsTrue()); //Less Than
            AssertThat(entityId <= entityId2, IsTrue()); //Equal
            AssertThat(entityId3 <= entityId, IsFalse()); //Greater Than
        });
        it("Should compare as Greater Than Or Equal correctly", [&]() {
            ECS::EntityId entityId(1234);
            ECS::EntityId entityId2(1234);
            ECS::EntityId entityId3(4321);
            AssertThat(entityId >= entityId3, IsFalse()); //Less Than
            AssertThat(entityId >= entityId2, IsTrue()); //Equal
            AssertThat(entityId3 >= entityId, IsTrue()); //Greater Than
        });
        it("Outputs to streams correctly", [&]() {
            ECS::EntityId entityId(1234);
            std::stringstream buffer;
            buffer << entityId;
            AssertThat(buffer.str(), Equals("EntityId[1234]"));
        });
    });
});
