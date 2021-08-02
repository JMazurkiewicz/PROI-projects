#pragma once

namespace impl {
    class NodeBase {
    public:
        NodeBase() {
            reset();
        }

        virtual ~NodeBase() = default;

        NodeBase(const NodeBase&) = delete;
        NodeBase& operator=(const NodeBase&) = delete;

        virtual void reset() {
            next = this;
            prev = this;
        }

        void hookBefore(NodeBase* nextNode) {
            next = nextNode;
            prev = nextNode->getPrevNode();
            prev->next = this;
            nextNode->prev = this;
        }

        void unhook() {
            NodeBase* const next = getNextNode();
            NodeBase* const prev = getPrevNode();
            next->prev = prev;
            prev->next = next;
            reset();
        }

        void hookFront(NodeBase* other) {
            other->next = this;
            prev = other;
        }

        void hookBack(NodeBase* other) {
            other->prev = this;
            next = other;
        }

        NodeBase* getNextNode() const {
            return next;
        }

        NodeBase* getPrevNode() const {
            return prev;
        }

    private:
        NodeBase* next;
        NodeBase* prev;
    };
} // namespace impl
