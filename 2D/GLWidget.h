/*************************************************************************
    CSC418/2504, Winter 20l5
    Assignment 1

    Instructions:
        See main.cpp for more instructions.

        This file contains the OpenGL portion of the main window.
**************************************************************************/

#ifndef __GLWidget_h__
#define __GLWidget_h__

#include "include_gl.h"
#include "GLState.h"
#include "GLShape.h"
#include <QtOpenGL/QtOpenGL>

// Before transformed, this class displays a unit square centered at the
// origin.
class UnitSquare : public GLShape
{
public:
    using GLShape::initialize;

    void initialize(int shader_input_location)
    {
	// Use two triangles to create the square.
        GLfloat square_vertices[][2] =
        {
            { -0.5, -0.5 },  // Triangle 1
            {  0.5, -0.5 },
            {  0.5,  0.5 },
            { -0.5, -0.5 },  // Triangle 2
            {  0.5,  0.5 },
            { -0.5,  0.5 },
        };

        initialize(
	    shader_input_location,
            reinterpret_cast<const GLfloat *>(square_vertices),
            /*num_vertices=*/6,
	    GL_TRIANGLES); // Each group of three coordinates is a triangle
    }
};

// Before transformed, this class displays a unit circle centered at the
// origin.
class UnitCircle : public GLShape
{
public:
    using GLShape::initialize;

    void initialize(int shader_input_location, int num_circle_segments)
    {
        // We will draw a circle as a triangle fan.  We are careful to send
	// the second coordinate twice to properly close the circle.
        //        3     2     1
        //         +----+----+
        //        / \   |   /
        //       /   \  |  /
        //      /     \ | /
        //     /       \|/
        //   4+---------+ 0
        //        ...
        std::vector<GLfloat> circle_vertices;
        circle_vertices.push_back(0.0);
        circle_vertices.push_back(0.0);
        for (int i=0; i<=num_circle_segments; ++i)
        {
            double angle = (2 * M_PI * i) / num_circle_segments;
            circle_vertices.push_back(cos(angle));
            circle_vertices.push_back(sin(angle));
        }

        initialize(
	    shader_input_location,
            &circle_vertices[0],
            num_circle_segments + 1,
	    GL_TRIANGLE_FAN);
    }
};

class UnitBody : public GLShape // custom unit shape for body
{
public:
    using GLShape::initialize;

    void initialize(int shader_input_location)
    {
	// Use two triangles to create the square.
        GLfloat body_vertices[][2] =
        {
            { -0.2, 0.5 },  // Triangle 1
            { -0.5, -0.3 },
            { -0.15, -0.5 },
            { -0.2, 0.5 },  // Triangle 2
            { -0.15, -0.5 },
            {  0.15, -0.5 },
            { -0.2, 0.5 },  // Triangle 3
            {  0.15, -0.5 },
            {  0.5, -0.3 },
            { -0.2, 0.5 },  // Triangle 4
            {  0.5, -0.3 },
            {  0.2, 0.5 },
        };

        initialize(
	    shader_input_location,
            reinterpret_cast<const GLfloat *>(body_vertices),
            /*num_vertices=*/12,
	    GL_TRIANGLES); // Each group of three coordinates is a triangle
    }
};

class UnitNeck : public GLShape // custom unit shape for head
{
public:
    using GLShape::initialize;

    void initialize(int shader_input_location)
    {
	// Use two triangles to create the square.
        GLfloat neck_vertices[][2] =
        {
            { -0.4, -0.3 },  // Triangle 1
            { -0.3,  0.3 },
            {  0.0,  0.4 },
            { -0.4, -0.3 },  // Triangle 2
            {  0.0,  0.4 },
            {  0.3,  0.2 },
            { -0.4, -0.3 },  // Triangle 3
            {  0.3,  0.2 },
            {  0.5, -0.3 },
        };

        initialize(
	    shader_input_location,
            reinterpret_cast<const GLfloat *>(neck_vertices),
            /*num_vertices=*/9,
	    GL_TRIANGLES); // Each group of three coordinates is a triangle
    }
};

class UnitBeakUp : public GLShape // custom unit shape for upper half beak
{
public:
    using GLShape::initialize;

    void initialize(int shader_input_location)
    {
	// Use two triangles to create the square.
        GLfloat beakup_vertices[][2] =
        {
            { -0.5, -0.5 },  // Triangle 1
            {  0.5, -0.5 },
            {  0.5,  1.0 },
            { -0.5, -0.5 },  // Triangle 2
            {  0.5,  1.0 },
            { -0.5,  0.5 },
        };
        initialize(
	    shader_input_location,
            reinterpret_cast<const GLfloat *>(beakup_vertices),
            /*num_vertices=*/6,
	    GL_TRIANGLES); // Each group of three coordinates is a triangle
    }
};

class UnitArm : public GLShape // custom unit shape for arm
{
public:
    using GLShape::initialize;

    void initialize(int shader_input_location)
    {
	// Use two triangles to create the square.
        GLfloat arm_vertices[][2] =
        {
            { -0.3, -0.5 },  // Triangle 1
            {  0.3, -0.5 },
            {  0.5,  0.5 },
            { -0.3, -0.5 },  // Triangle 2
            {  0.5,  0.5 },
            { -0.5,  0.5 },
        };
        initialize(
	    shader_input_location,
            reinterpret_cast<const GLfloat *>(arm_vertices),
            /*num_vertices=*/6,
	    GL_TRIANGLES); // Each group of three coordinates is a triangle
    }
};

class UnitFoot : public GLShape // custom unit shape for foot
{
public:
    using GLShape::initialize;

    void initialize(int shader_input_location)
    {
	// Use two triangles to create the square.
        GLfloat foot_vertices[][2] =
        {
            { -0.5, -0.8 },  // Triangle 1
            {  0.5, -0.5 },
            {  0.5,  0.5 },
            { -0.5, -0.8 },  // Triangle 2
            {  0.5,  0.5 },
            { -0.5,  0.5 },
        };
        initialize(
	    shader_input_location,
            reinterpret_cast<const GLfloat *>(foot_vertices),
            /*num_vertices=*/6,
	    GL_TRIANGLES); // Each group of three coordinates is a triangle
    }
};

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    // These values control the bounds to display on the joint angle sliders.
    static const int JOINT_MIN = -30;
    static const int JOINT_MAX = 30;
    static const int BODY_MOVE_HORIZONTAL_MIN = -50;
    static const int BODY_MOVE_HORIZONTAL_MAX = 50;
    static const int BODY_MOVE_VERTICAL_MIN = -20;
    static const int BODY_MOVE_VERTICAL_MAX = 20;
    static const int NECK_JOINT_MIN = -15;
    static const int NECK_JOINT_MAX = 15;
    static const int BEAK_MOVE_VERTICAL_MIN = 10;
    static const int BEAK_MOVE_VERTICAL_MAX = 20;
    static const int FOOT_JOINT_MIN = -105;  // Left is -, Right is +
    static const int FOOT_JOINT_MAX = -75;
    static const int ARM_JOINT_MIN = -30;
    static const int ARM_JOINT_MAX = 30;

    GLWidget(QWidget *parent=NULL);

public slots:
    // This method is called when the user changes the joint angle slider.

    void setBodyHorizontalPosition(int trans)
    {
        // This method is called when the user changes the slider value.
        body_move_horizontal_trans = trans;
        // Call update() to trigger a redraw.
        update();
    }
    void setBodyVerticalPosition(int trans)
    {
        // This method is called when the user changes the slider value.
        body_move_vertical_trans = trans;
        // Call update() to trigger a redraw.
        update();
    }
    void setNeckJointAngle(int angle)
    {
        // This method is called when the user changes the slider value.
        neck_joint_angle = angle;
        // Call update() to trigger a redraw.
        update();
    }
    void setBeakVerticalPosition(int trans)
    {
        // This method is called when the user changes the slider value.
        beak_move_vertical_trans = trans;
        // Call update() to trigger a redraw.
        update();
    }
    void setLeftArmJointAngle(int angle)
    {
        // This method is called when the user changes the slider value.
        leftarm_joint_angle = angle;
        // Call update() to trigger a redraw.
        update();
    }

    void setLeftLegJointAngle(int angle)
    {
        // This method is called when the user changes the slider value.
        leftleg_joint_angle = angle;
        // Call update() to trigger a redraw.
        update();
    }
    void setLeftFootJointAngle(int angle)
    {
            // This method is called when the user changes the slider value.
	leftfoot_joint_angle = angle;
            // Call update() to trigger a redraw.
            update();
    }
    void setRightLegJointAngle(int angle)
    {
            // This method is called when the user changes the slider value.
    	rightleg_joint_angle = angle;
            // Call update() to trigger a redraw.
            update();
    }
    void setRightFootJointAngle(int angle)
    {
            // This method is called when the user changes the slider value.
    	rightfoot_joint_angle = angle;
            // Call update() to trigger a redraw.
            update();
    }

    void onPressAnimate(int is_animating)
    {
        // This method is called when the user changes the animation checkbox.
        m_is_animating = (bool)is_animating;
        m_animation_frame = 1;
        update();
    }

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void drawNeck(const float NECK_X_SCALE, const float NECK_Y_SCALE,
                   const float BEAK_UP_X_SCALE, const float BEAK_UP_Y_SCALE,
                   const float BEAK_DOWN_X_SCALE, const float BEAK_DOWN_Y_SCALE,
                   const float BODY_Y_SCALE);
    void drawBeak(const float NECK_X_SCALE,
                    const float BEAK_DOWN_X_SCALE, const float BEAK_DOWN_Y_SCALE,
                    const float BEAK_UP_X_SCALE, const float BEAK_UP_Y_SCALE);
    void drawLeftArm(const float ARM_X_SCALE, const float ARM_Y_SCALE);
    void drawRightLegFoot(const float LEG_X_SCALE, const float LEG_Y_SCALE,
                            const float LEG_X_INV_SCALE, const float LEG_Y_INV_SCALE,
                            const float FOOT_X_SCALE, const float FOOT_Y_SCALE);
    void drawRightFoot(const float LEG_X_SCALE, const float LEG_Y_SCALE,
                            const float FOOT_X_SCALE, const float FOOT_Y_SCALE);
    void drawLeftLegFoot(const float LEG_X_SCALE, const float LEG_Y_SCALE,
                            const float LEG_X_INV_SCALE, const float LEG_Y_INV_SCALE,
                            const float FOOT_X_SCALE, const float FOOT_Y_SCALE);
    void drawLeftFoot(const float LEG_X_SCALE, const float LEG_Y_SCALE,
                            const float FOOT_X_SCALE, const float FOOT_Y_SCALE);

    void drawJoint(const float JOINT_X_TRANS, const float JOINT_Y_TRANS);
    void timerEvent(QTimerEvent *event);

private:
    GLTransformStack &transformStack()
    { return m_gl_state.transformStack(); }

private:
    GLState m_gl_state;
    bool m_is_animating;
    int m_animation_frame;
    UnitSquare m_unit_square;
    UnitCircle m_unit_circle;
    UnitBody m_unit_body;
    UnitNeck m_unit_neck;
    UnitBeakUp m_unit_beakup;
    UnitArm m_unit_arm;
    UnitFoot m_unit_foot;

    double m_joint_angle;
    double body_move_horizontal_trans;
    double body_move_vertical_trans;
    double neck_joint_angle;
    double beak_move_vertical_trans;
    double leftarm_joint_angle;
    double rightarm_joint_angle;
    double leftleg_joint_angle;
    double leftfoot_joint_angle;
    double rightleg_joint_angle;
    double rightfoot_joint_angle;
};

#endif
