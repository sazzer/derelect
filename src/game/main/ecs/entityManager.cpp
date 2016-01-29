#include "entityManager.hpp"
#include <list>
#include <algorithm>

namespace ECS {
    /** The current next ID to use */
    static EntityId::idType nextId = 0;

    /** The type to use in the Component List */
    typedef std::pair<EntityId, std::shared_ptr<Component>> ComponentListType;

    /** The list of components we know about */
    static std::list<ComponentListType> components;

    /**
     * Generate a new, guaranteed unique, Entity ID
     * @return the new Entity ID
     */
    EntityId generateEntityId() {
        EntityId::idType id = ++nextId;
        return EntityId(id);
    }

    /**
     * Add a Component to an Entity
     * @param entityId the Entity to add the component to
     * @param component The component to add to the entity
     */
    void addComponentToEntity(const EntityId& entityId, const std::shared_ptr<Component> component) {
        components.push_back(ComponentListType(entityId, component));
    }

    /**
     * Get the Component Names for the given Entity ID
     * @param entityId the Entity to get the component names for
     * @return the set of component names
     */
    const std::set<Component::nameType> getComponentNamesForEntity(const EntityId& entityId) {
        std::set<Component::nameType> names;
        for (const ComponentListType& component : components) {
            if (component.first == entityId) {
                names.insert(component.second->name());
            }
        }
        return names;
    }

    /**
     * Determine if the given Entity has a component with the given name
     * @param entityId the ID of the Entity
     * @param component The name of the component to look for
     * @return True if the Entity has the given Component. False if not
     */
    bool entityHasComponent(const EntityId& entityId, const Component::nameType& component) {
        return getComponentNamesForEntity(entityId).count(component) > 0;
    }

    /**
     * Remove a Component from an Entity
     * @param entityId the Entity to remove the component from
     * @param component The name of the component to remove from the entity
     */
    void removeComponentFromEntity(const EntityId& entityId, const Component::nameType component) {
        components.remove_if([&](auto c) {
            return c.first == entityId && c.second->name() == component;
        });
    }
}
