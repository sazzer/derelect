#ifndef DERELECT_GAME_ECS_ENTITYMANAGER_H
#define DERELECT_GAME_ECS_ENTITYMANAGER_H

#include "entityId.hpp"

namespace ECS {
    /**
     * Generate a new, guaranteed unique, Entity ID
     * @return the new Entity ID
     */
    EntityId generateEntityId();
}

#endif // DERELECT_GAME_ECS_ENTITYMANAGER_H
