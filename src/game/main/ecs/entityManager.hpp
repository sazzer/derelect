#ifndef DERELECT_GAME_ECS_ENTITYMANAGER_H
#define DERELECT_GAME_ECS_ENTITYMANAGER_H

#include "entityId.hpp"
#include "component.hpp"
#include <set>
#include <string>
#include <memory>

namespace ECS {
    /**
     * Generate a new, guaranteed unique, Entity ID
     * @return the new Entity ID
     */
    EntityId generateEntityId();

    /**
     * Add a Component to an Entity
     * @param entityId the Entity to add the component to
     * @param component The component to add to the entity
     */
    void addComponentToEntity(const EntityId& entityId, const std::shared_ptr<Component> component);

    /**
     * Remove a Component from an Entity
     * @param entityId the Entity to remove the component from
     * @param component The name of the component to remove from the entity
     */
    void removeComponentFromEntity(const EntityId& entityId, const Component::nameType component);

    /**
     * Determine if the given Entity has a component with the given name
     * @param entityId the ID of the Entity
     * @param component The name of the component to look for
     * @return True if the Entity has the given Component. False if not
     */
    bool entityHasComponent(const EntityId& entityId, const Component::nameType& component);

    /**
     * Get the Component Names for the given Entity ID
     * @param entityId the Entity to get the component names for
     * @return the set of component names
     */
    const std::set<Component::nameType> getComponentNamesForEntity(const EntityId& entityId);
}

#endif // DERELECT_GAME_ECS_ENTITYMANAGER_H
