# include/vsg/core headers
The **include/vsg/core** header directory contains the base classes, smart pointers and memory management classes.


## Base Object classes

* [include/vsg/core/Object.h](Object.h) - main base class that provides intrusive std::atomic based thread safe reference counting and meta data interface
* [include/vsg/core/Auxiliary.h](Auxiliary.h) - an optional object class used by vsg::Object to store meta data when required, or links to allocators used.

## Smart pointers & Memory management classes
* [include/vsg/core/ref_ptr.h](ref_ptr.h) - template smart pointer class that uses vsg::Object's intrusive reference count to robustly management object lifetime. Similar to role std::shared_ptr<> but higher performance virtual of having half the memory footprint, holding just a single C pointer internally rather than two pointers that std::shared_ptr<> requires.
* [include/vsg/core/observer_ptr.h](observer_ptr.h) - template smart pointer class for non owning pointer references. Similar in role to std::weak_ptr<> but works with the VSG's intrusive reference counting.
* [include/vsg/core/Allocator.h](Allocator.h) - base class that provides a standard interface for custom allocation and deleting of allocated memory.

## Data container classes
* [include/vsg/core/Data.h](Data.h) - base class that abstracts the provision of data (typically passed to Vulkan or for storing meta data.)
* [include/vsg/core/Value.h](Value.h) - template Data class that provides a single simple type (such as int, vsg::vec2 etc.)  Typical uses : storing meta data values, uniforms and vertex array data.
* [include/vsg/core/Array.h](Array.h) - template Data class that provides an 1D Array of simpler types (such as int, vsg::vec2 etc.).  Typical uses : storing uniforms, vertex array data, and 1D texture/image data.

## Visitor pattern classes

* [include/vsg/core/Visitor.h](Visitor.h) - base visitor class for non const objects/graphs
* [include/vsg/core/ConstVisitor.h](ConstVisitor.h) - base visitor class for const objects/graphs

## C++ template helper classes
* [include/vsg/core/Inherit.h](Inherit.h) - Curiously Recurring Template Pattern used to implement standardized visitor, traversal and memory allocation methods

## General build support headers 
* [include/vsg/core/Export.h](Export.h) - provides Windows __declspec() macros abstraction
* [include/vsg/core/Version.h](Version.h) - autogenerated header with libvsg version information
