#include "entityId.hpp"

namespace ECS {
    /**
     * Equality Operator for Entity IDs
     * @param a The first Entity ID to compare
     * @param b The second Entity ID to compare
     * @return true if the two are the same. False if Not
     */
    bool operator==(const EntityId& a, const EntityId& b) {
        return a.id() == b.id();
    }

    /**
     * Less Than Operator for Entity IDs
     * @param a The First Entity to compare
     * @param b The Second Entity to compare
     * @return true if a < b. False if Not
     */
    bool operator<(const EntityId& a, const EntityId& b) {
        return a.id() < b.id();
    }
    /**
     * Left Shift Operator for writing to output streams
     * @param os The stream to write to
     * @param id The ID to write
     * @return the output stream
     */
    std::ostream& operator<<(std::ostream& os, const EntityId& id) {
        os << "EntityId[" << id.id() << "]";
        return os;
    }

}
