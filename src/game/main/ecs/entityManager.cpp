#include "entityManager.hpp"

namespace ECS {
    /** The current next ID to use */
    static EntityId::idType nextId = 0;

    /**
     * Generate a new, guaranteed unique, Entity ID
     * @return the new Entity ID
     */
    EntityId generateEntityId() {
        EntityId::idType id = ++nextId;
        return EntityId(id);
    }
}
