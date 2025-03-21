# Overview

You will create a tree data structure wherein each node contains a transformation matrix, and child nodes inherit the transformations of their parent nodes. During this process you will reinforce your knowledge of C++ pointers and polymorphism as well as linear algebra transformation sequences. 



# Supplied Code

We will provide you with a basic Qt GUI that consists of only a window with a widget to render 2D scenes using OpenGL. You are free to organize your code and classes however you like as long as they adhere to the requirements outlined below. Additionally, we have provided a robust library of linear algebra functions called GLM (OpenGL Mathematics) to use for your transformation needs. The library you wrote for homework 1 was designed to be very similar in format to the classes and functions provided by GLM, but there are some differences in inputs to the transformation matrix functions GLM provides.

[You can find the documentation for GLM here.](http://glm.g-truc.net/0.9.8/api/index.html)

When your project runs successfully, you should see the scene below. You can toggle the grid off and on by pressing the `G` key on your keyboard.





We have also recorded a video showcasing the functionality expected from your homework implementation 

- [Link](https://www.cis.upenn.edu/~cis4600/25sp/hw/hw02/hw02_demo_video.mp4)

# Instructions

## Header files

We have provided you `smartpointerhelp.h`, which contains some preprocessor definitions to make it easier for you to write out smart pointer syntax. Please make use of these abbreviations as you implement the classes described below.



## Node Classes

A scene graph is a node-based tree data structure used to organize geometry in computer graphics. We have provided you with `node.h` inside the `scene` folder. You will create a basic `Node` class which should support the following features:

- A set of `unique_ptr`s to the node's children. We recommend using `std::vector`s to store the pointers, since they act as dynamically resizeable arrays.
- A raw, C-style pointer to one instance of `Polygon2D`. As noted later in the writeup, this `Polygon2D` will be stored on the stack, so smart pointers are not relevant. Note that a `Node` does not have to point to `Polygon2D`, so a reference is also not applicable, as they cannot have a value of `nullptr`.
- The color with which to draw the `Polygon2D` pointed to by the node, if applicable. This should be stored as a Red Green Blue (RGB) value in a `vec3` with elements in the range [0,1]. You will use this to temporarily override the color attribute of the `Polygon2D` pointed to by this node. This enables you to draw the same basic `Polygon2D` with differing transformations and colors without having to create a duplicate, as demonstrated in the example scene drawing code in `MyGL::paintGL`.
- A copy constructor and assignment operator (`operator=`).
- A **purely virtual** `clone` function that returns a deep copy of the node it's invoked on. It should return a `uPtr<Node>`.
- A **purely virtual** function that computes and returns a 3x3 homogeneous matrix representing the transformation in the node.
- A QString to represent a name for the node. This will be used later on when you create a GUI to display your scene graph nodes.
- A function that adds a given `unique_ptr` as a child to this node. You'll have to make use of `std::move` to make this work. Additionally, to make scene graph construction easier for you, this function should return a `Node&` that refers directly to the `Node` that is pointed to by the `unique_ptr` passed into the function. This will allow you to modify that heap-based `Node` from within your scene graph construction function without worrying about `std::move`-ing unique pointers around.
- A function that allows the user to modify the color stored in this node.

Additionally, you will create the following classes that inherit from the basic `Node` class:

- `TranslateNode`, which stores two floating point numbers: one that represents its translation in the X direction, and one that represents its translation in the Y direction.
- `RotateNode`, which stores one floating point number which represents the magnitude of its rotation in degrees.
- `ScaleNode`, which stores two floating point numbers: one that represents its scale in the X direction, and one that represents its scale in the Y direction.

All three subclasses should implement the purely virtual function you declared in your `Node` class that computes and returns a 3x3 transformation matrix. Additionally, make sure you remember to use initializer lists in your constructors and to make your destructors `virtual`. Make sure your `Node` subclass constructors invoke a `Node` constructor for good style, in addition to instantiating the unique member variables of each subclass.

## Scene graph construction

Add a member variable to `MyGL` that represents the root node of your scene graph. You should make it a unique pointer to a generic `Node`. Then, write a function that you invoke from within `MyGL::initializeGL` that constructs your entire scene graph and returns its root node, which you will store in `MyGL`'s member variable. Any `Polygon2D` that your scene graph points to should be stored in `MyGL` rather than on the heap. Furthermore, you may re-use base geometry to draw the same shape with different transformations by having two different `Node`s point to that shape instance.

Within your scene graph construction function, you will build a scene graph that forms a humanoid puppet. This puppet must have the following features:

- At least two limbs that each have two segments, e.g. upper arm and forearm. Each arm segment must pivot about one of its ends, such that if both segments are rotated the limb curls as an arm or leg would.
- A head or head-analogue that pivots about its base. You may choose to include a neck if you wish.
- A torso that serves as the "root" of all body transformations. In other words, any transformations you apply to the torso should apply to the rest of the character's body.



## Scene Graph Traversal

Implement a function that takes in a pointer to a `Node` and a `mat3`, and which traverses your scene graph and draws any existing `Polygon2D`s at each `Node` using the sequence of transformation matrices that have been concatenated thus far, following the example in the lecture slides. You should invoke this function from `MyGL::paintGL`. Note that because `Node`s store their children in a vector of `unique_ptr`s, you will have to do one of two things to read them:

- Use a foreach loop to the effect of `for(const uPtr& n : node->children)`. This enables you to read the children without transferring ownership to `traverse` because you're not creating a second `unique_ptr`, just a reference to one.
- Use the smart pointer `get()` function to grab a raw pointer to each child, achieving a similar effect to the code above as this also does not create a second `unique_ptr`. We strongly recommend the first option since it precludes the possibility of freeing memory owned by a smart pointer by invoking `delete` on a raw pointer.



## Qt GUI

The following elements have been provided in your GUI in order to facilitate interactive alteration of your nodes' transformation values. You can edit the GUI that appears when you run your program by opening `Forms/forms/mainwindow.ui` in Qt Creator:

- A Tree Widget used to display your scene graph nodes. See the explanation in the next paragraph for more information.
- A set of five Spin Boxes that enable the user to edit the translation, rotation, and scale of a given node.
- A button that, when clicked, sets the geometry pointer of the currently selected node to be `MyGL`'s `m_geomSquare` if that node does not already have geometry.
- Three buttons that each allow the user to add a new node as a child of the currently selected node, with one button for each type of node (translate, rotate, and scale).

**Important Note:** None of the provided GUI elements have been set up to actually implement their required functionality. While you can alter the numbers inside the spin boxes, for example, they will not yet alter anything. You must add `slots` to `MyGL` and connect them to the `signals` emitted by these GUI elements by invoking the `connect` function in `MainWindow`. You can refer to the provided calls to `connect` in `mainwindow.cpp` to see how to set up further calls.

In order for your Tree Widget to display your nodes, you will have to add the following functionality to your node class:

- Have your node class inherit from the `QTreeWidgetItem` class (this has been done for you).
- In the function you wrote to add a node as a child to another node, invoke `QTreeWidgetItem::addChild`, with the child node as the input. Note that this function takes in a `QTreeWidgetItem*`, and recall that `Node` inherits from `QTreeWidgetItem`. Also recall that you can get a raw C-style pointer to the address owned by a smart pointer via the `get()` function.
- In the body of your node's constructor(s), invoke `setText` on your node's name. This will allow the name to show up in the tree widget. `setText` is a member function of the `QTreeWidgetItem` class that gives it a display name in a `QTreeWidget`.
- Just after you invoke your scene graph building function in `MyGL`, have `MyGL` emit its signal `sig_sendRootNode` with the root node of your scene graph as its argument. This signal is connected to a slot in `MainWindow` that adds the given `QTreeWidgetItem` as a "top-level item" to the `QTreeWidget` in the GUI. In other words, it adds the item as a root node in the GUI.

You can find a guide to editing Qt GUIs under the Resources tab of the web site.



## Style

To help you write better C++ code, we will score each of your homework assignments on three different style elements, which will change from week to week. For this assignment, make sure you:

- Implement a copy constructor, assignment operator, and (appropriately virtual) destructor for any classes you author. Consider writing a `clone` function to facilitate deep copying the children of a node.
- Only declare member functions/variables as public when they **need** to be public. Everything else should be private or protected.
- Never use the `new` or `delete` keywords anywhere in your program.



## Extra Credit

Include a readme.txt file in your repository that lists which extra credit features you implemented and how to display them.

### Artistically interesting scene

Go beyond the basic requirements for your puppet and add detail to your scene. Give your character a face, props, clothing, etc. Have fun with it! The more detail, the more points!

### Polished GUI (5 - 10 pts)

Connect signals and slots in your GUI such that when a particular type of node is selected in your tree widget, only the transformation adjustment widgets that are compatible with that node are "active". For additional points, alter the visual style of your GUI with Qt style sheets so it looks more professional and less "default Windows/OSX user interface".

### Support concave polygons (15 pts)

Modify the constructor of `Polygon2D` that takes in a list of vertices such that its triangulation process works on both concave and convex polygons. You may have to add additional vertices to the polygon to make this work.
