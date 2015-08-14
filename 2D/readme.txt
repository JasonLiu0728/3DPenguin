1. Overview
A 2D penguin that consists of 9 shapes and 6 joints is hierarchically rendered using
Qt and OpenGL version 3.30. This penguin has 9 degrees of freedom, which includes
6 rotations (each joint corresponds to a rotation), 1 way translational motion - up
and down - of the lower half of the beak, and 2 way translational motion - up and down,
left and right - of the entire penguin. The render hierarchy and details of specific
parts are explained in the following sections.

2. Render Hierarchy

Root                Body

Branch Level 1      head and its parts, call function "drawNeck"
                    left arm and its parts, call function "drawLeftArm"
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

3. Animation
All parts mainly use sine function for back-and-forth movements.

4. Parts and Details
4.1 Body
For rendering of the penguin's body, a custom shape is created that consists of 4 triangles.
The shape resembles that of the body of the penguin shown in the instructions for Part B. There
are no transformations for this body part. However, as mentioned in the overview, the entire
penguin can move up, down, left and right.

4.2 Head and Beaks
For rendering of the penguin's head, a custom shape is created that consists of 3 triangles.
The shape resembles that of the head of the penguin shown in the instructions for Part B. There
is a neck joint for rotation of head relative to the body, animating looking up or down. In addition,
there are 2 beak parts as the children of the head.

4.2.1 Beaks
A custom shape is created for the upper beak that consists of 2 triangles, and the shape
resembles that of the upper beak shown in the instructions for Part B. There is a translational
transformation for the lower half beak - moving up or down - that animates the closing or opening
of the mouth.

4.3 Legs and Feet
Besides positioning and animation timing, left leg and foot are equivalent to right leg and foot,
so both are discussed together. There is a leg joint for rotation of leg relative to the body,
necessary for animating walking. In addition, there is the foot as the child of the leg.

4.3.1 Feet
A custom shape is created for the foot that consists of 2 triangles, and the shape resembles
that of the foot shown in the instructions for Part B. There is a foot joint for rotation of
foot relative to the leg, necessary for animating foot rotations during walking.

5. Conclusions and Guide for Understanding Code
For easiness of controlling transformations, each degree of freedom corresponds to a sliding
bar in the application window. Some efforts were dedicated to organize transformations into
functions, which make the hierarchy and the structure of the code clearer.

