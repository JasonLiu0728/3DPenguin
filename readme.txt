This is a simple OpenGL demo that shows the animations of a 3D penguin.

1. Overview
A 3D penguin that is capable of 24 degrees of freedom is hierarchically rendered using
Qt and OpenGL version 1.20. In addition, 5 rendering styles - wireframe, solid, outlined,
shiny metal, matte - are available. For visualizing shiny metal and matte materials,
upon selecting the rendering style, one light source is automatically enabled. The user
can then adjust the light source positions in light source control panel. A sample animation
using keyframes is included to demonstrate the physical abilities of the penguin.

2. Key files
main.cpp       - all major functions
keyframe.h     - Keyframe class function headers; includes all motion and light source parameters
parts.h        - unit shape definitions for penguin parts
colorpalette.h - color definitions

3. Rendering

3.1 Render Hierarchy
Root                Body

Branch Level 1      head and its parts, call function "renderHead"
                    left arm and its parts, call function "renderShoulderL"
                    right arm and its parts, call function "renderShoulderR"
                    right leg and its parts, call function "drawRightLegFoot"
                    left leg and its parts, call function "drawLeftLegFoot"

Branch Level 2      head, neck joint and beaks, call functions "drawBeak" and "drawJoint"
                    left arm and left arm joint, call function "drawJoint"
                    right leg, right leg joint and right foot, call functions "drawJoint"
                    and "drawRightFoot"
                    left leg, left leg joint and left foot, call functions "drawJoint"
                    and "drawLeftFoot"

Branch Level 3      lower half beak and upper half beak
                    right foot and right foot joint, call function "drawJoint"
                    left foot and left foot joint, call function "drawJoint"

3.2 GL Functions used
The following GL functions are enabled during rendering,

glEnable(GL_DEPTH_TEST) - depth buffering
glDepthFunc(GL_LESS)
glEnable(GL_LINE_SMOOTH) - smooth wireframe lines
glEnable(GL_LIGHTING) - enable lighting

Other functions that set the parameters for rendering, such as glPolygonMode, glColor3fv,
are also used but are not detailed here as they are common and widely used as standard
practices.

4. Light source and materials
Light source can rotate around the y-axis, on the xz plane, or rotate around the z-axis,
on the xy plane. The materials that reflect light are shiny metal and matte material.
In particular, shiny metal uses GL_SPECULAR material property defined in openGL, and
matte material uses GL_DIFFUSE material property defined in openGL.

Changes in light source are not updated real-time. The user needs to render the material
again to see the changes. For example, the user can switch to another material and switch
back.

5. Animation
GUI has Joint Control panel that controls all degrees of freedom, which enables the user
to inspect any part of the penguin and its associated movements. In addition, a keyframe
file is created that contains 15 keyframes, which demonstrate penguin walking and jumping,
combined with changes in camera angles.

6. Conclusions and Guide for Understanding Code
Some efforts were dedicated to organize major components of the code into functions. For
easiness of understanding the code, the following major functions can be looked at,

RenderInit() - initializes all GL functions necessary
RenderScene() - all calls to draw the geometries, render the materials, and transformations

Other codes are added in their relevant chunks. For example, light source control panel is
added in the GLUI window chunk of code.
