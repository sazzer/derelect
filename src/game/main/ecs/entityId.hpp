#ifndef DERELECT_GAME_ECS_ENTITYID_H
#define DERELECT_GAME_ECS_ENTITYID_H

#include <cstdint>
#include <utility>
#include <ostream>

namespace ECS {
    /**
     * Representation of the ID of an Entity. This makes it typesafe refering to these
     */
    class EntityId {
    public:
        /**
         * Construct the Entity ID
         * @param id The actual ID to use
         */
        explicit EntityId(const uint64_t id) : id_(id) {}
        /**
         * Get the actual ID
         * @return the actual ID
         */
        uint64_t id() const {
            return id_;
        }
    protected:
    private:
        /** The actual ID of the Entity */
        const uint64_t id_;
    };

    /**
     * Equality Operator for Entity IDs
     * @param a The first Entity ID to compare
     * @param b The second Entity ID to compare
     * @return true if the two are the same. False if Not
     */
    bool operator==(const EntityId& a, const EntityId& b);

    /**
     * Less Than Operator for Entity IDs
     * @param a The First Entity to compare
     * @param b The Second Entity to compare
     * @return true if a < b. False if Not
     */
    bool operator<(const EntityId& a, const EntityId& b);

    /**
     * Left Shift Operator for writing to output streams
     * @param os The stream to write to
     * @param id The ID to write
     * @return the output stream
     */
    std::ostream& operator<<(std::ostream& os, const EntityId& id);
}
using namespace std::rel_ops;

#endif // DERELECT_GAME_ECS_ENTITYID_H
