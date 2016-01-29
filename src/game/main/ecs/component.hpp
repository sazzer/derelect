#ifndef DERELECT_GAME_ECS_COMPONENT_H
#define DERELECT_GAME_ECS_COMPONENT_H

#include <string>

namespace ECS {
    /**
     * Representation of a Component assigned to an Entity
     */
    class Component {
    public:
        /** The type to use for the name of the component */
        typedef std::string nameType;

        /**
         * Virtual Destructor
         */
        virtual ~Component() {}
        
        /**
         * Get the Name of the Component
         * @return the name of the Component
         */
        virtual nameType name() const = 0;
    protected:
    private:
    };
}

#endif // DERELECT_GAME_ECS_COMPONENT_H
