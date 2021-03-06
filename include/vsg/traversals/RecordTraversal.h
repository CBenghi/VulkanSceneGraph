#pragma once

/* <editor-fold desc="MIT License">

Copyright(c) 2018 Robert Osfield

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

</editor-fold> */

#include <vsg/core/Object.h>
#include <vsg/core/type_name.h>
#include <vsg/maths/mat4.h>

namespace vsg
{

    // forward declare nodes
    class Node;
    class Group;
    class QuadGroup;
    class LOD;
    class PagedLOD;
    class StateGroup;
    class CullGroup;
    class CullNode;
    class MatrixTransform;
    class Command;
    class Commands;
    class CommandBuffer;
    class State;
    class DatabasePager;
    class FrameStamp;
    class CulledPagedLODs;
    class View;

    class RecordTraversal;
    VSG_type_name(vsg::RecordTraversal);

    class VSG_DECLSPEC RecordTraversal : public Object
    {
    public:
        explicit RecordTraversal(CommandBuffer* commandBuffer = nullptr, uint32_t maxSlot = 2, FrameStamp* fs = nullptr);
        ~RecordTraversal();

        std::size_t sizeofObject() const noexcept override { return sizeof(RecordTraversal); }
        const char* className() const noexcept override { return type_name<RecordTraversal>(); }

        State* getState() { return _state; }

        void setFrameStamp(FrameStamp* fs);
        FrameStamp* getFrameStamp() { return _frameStamp; }

        void setDatabasePager(DatabasePager* dp);
        DatabasePager* getDatabasePager() { return _databasePager; }

        void setProjectionAndViewMatrix(const dmat4& projMatrix, const dmat4& viewMatrix);

        void apply(const Object& object);

        // scene graph nodes
        void apply(const Group& group);
        void apply(const QuadGroup& quadGrouo);
        void apply(const LOD& lod);
        void apply(const PagedLOD& pagedLOD);
        void apply(const CullGroup& cullGroup);
        void apply(const CullNode& cullNode);

        // Vulkan nodes
        void apply(const MatrixTransform& mt);
        void apply(const StateGroup& object);
        void apply(const Commands& commands);
        void apply(const Command& command);

        // Viewer level nodes
        void apply(const View& view);

    private:
        FrameStamp* _frameStamp = nullptr;
        State* _state = nullptr;

        // used to handle loading of PagedLOD external children.
        DatabasePager* _databasePager = nullptr;
        CulledPagedLODs* _culledPagedLODs = nullptr;
    };

} // namespace vsg
