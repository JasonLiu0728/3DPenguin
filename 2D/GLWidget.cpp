/*************************************************************************
    CSC418/2504, Winter 20l5
    Assignment 1

    Instructions:
        See main.cpp for more instructions.

        This file contains the class OpenGL portion of the main window.
**************************************************************************/

#include "GLWidget.h"
#include <iostream>

static QGLFormat createQGLFormat()
{
    // Return a QGLFormat object that tells Qt information about what
    // OpenGL context we would like.
    QGLFormat format(QGL::SampleBuffers);
    if (supportsNewOpenGL())
    {
	// Choose a version of OpenGL that supports vertex array objects and
	// tell it that we do not want support for deprecated functions.
        format.setVersion(3, 3);
        format.setProfile(QGLFormat::CoreProfile);
    }
    return format;
}

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(createQGLFormat(), parent)
    , m_is_animating(false)
    , m_animation_frame(0)
    , m_joint_angle(0)
{
    // Start a timer that will call the timerEvent method every 50ms.
    startTimer(/*milliseconds=*/50);
}

void GLWidget::initializeGL()
{
    m_gl_state.initializeGL();

    // To aid with troubleshooting, print out which version of OpenGL we've
    // told the driver to use.
    std::cout << "Using OpenGL: " << glGetString(GL_VERSION) << std::endl;

    // Copy the data for the shapes we'll draw into the video card's memory.
    // Custom shapes of the body, neck, upper half beak, arm and joint are also
    // copied into the video card's memory
    m_unit_square.initialize(m_gl_state.VERTEX_POSITION_SHADER_LOCATION);
    m_unit_body.initialize(m_gl_state.VERTEX_POSITION_SHADER_LOCATION);
    m_unit_neck.initialize(m_gl_state.VERTEX_POSITION_SHADER_LOCATION);
    m_unit_beakup.initialize(m_gl_state.VERTEX_POSITION_SHADER_LOCATION);
    m_unit_arm.initialize(m_gl_state.VERTEX_POSITION_SHADER_LOCATION);
    m_unit_foot.initialize(m_gl_state.VERTEX_POSITION_SHADER_LOCATION);
    m_unit_circle.initialize(
	m_gl_state.VERTEX_POSITION_SHADER_LOCATION,
	/*num_circle_segments=*/100);

    // Tell OpenGL what color to fill the background to when clearing.
    glClearColor(/*red=*/0.7f, /*green=*/0.7f, /*blue=*/0.9f, /*alpha=*/1.0f);

}

void GLWidget::resizeGL(int width, int height)
{
    // Respond to the window being resized by updating the viewport and
    // projection matrices.

    checkForGLErrors();

    // Setup projection matrix for new window
    m_gl_state.setOrthographicProjectionFromWidthAndHeight(width, height);

    // Update OpenGL viewport and internal variables
    glViewport(0, 0, width, height);
    checkForGLErrors();
}

void GLWidget::timerEvent(QTimerEvent *)
{
    // Respond to a timer going off telling us to update the animation.
    if (!m_is_animating)
        return;

    // increment the frame number.
    m_animation_frame++;

    // Update translation, they all use sine function
	const double beak_trans_speed = 0.1;
	const double trans_speed = 0.01;
	bool horizontal = true;
	double beak_trans_t = ( sin(m_animation_frame * beak_trans_speed) + 1.0 ) / 2.0;
	double trans_t = m_animation_frame * trans_speed;
	//if(horizontal) {body_move_horizontal_trans = trans_t * BODY_MOVE_HORIZONTAL_MIN +
        //                        (1 - trans_t) * BODY_MOVE_HORIZONTAL_MAX;}
	if(horizontal) {body_move_horizontal_trans = trans_t * BODY_MOVE_HORIZONTAL_MIN +
                                (1 - trans_t) * BODY_MOVE_HORIZONTAL_MAX;}
    else {body_move_vertical_trans = trans_t * BODY_MOVE_VERTICAL_MIN +
                                (1 - trans_t) * BODY_MOVE_VERTICAL_MAX;}
        beak_move_vertical_trans = beak_trans_t * BEAK_MOVE_VERTICAL_MIN +
                                (1 - beak_trans_t) * BEAK_MOVE_VERTICAL_MAX;

    // Update joint angles, they all use sine function
    const double joint_rot_speed = 0.1;
    double joint_rot_t = ( sin(m_animation_frame * joint_rot_speed) + 1.0 ) / 2.0;
    neck_joint_angle = joint_rot_t * NECK_JOINT_MIN + (1 - joint_rot_t) * NECK_JOINT_MAX;
    leftarm_joint_angle = joint_rot_t * ARM_JOINT_MIN + (1 - joint_rot_t) * ARM_JOINT_MAX;
    leftleg_joint_angle = joint_rot_t * JOINT_MIN + (1 - joint_rot_t) * JOINT_MAX;
    leftfoot_joint_angle = joint_rot_t * FOOT_JOINT_MIN + (1 - joint_rot_t) * FOOT_JOINT_MAX;
    rightleg_joint_angle = -(joint_rot_t * JOINT_MIN + (1 - joint_rot_t) * JOINT_MAX);
    rightfoot_joint_angle = joint_rot_t * FOOT_JOINT_MIN + (1 - joint_rot_t) * FOOT_JOINT_MAX;

    // Tell this widget to redraw itself.
    update();
}

void GLWidget::paintGL()
{
    // This method gets called by the event handler to draw the scene, so
    // this is where you need to build your scene -- make your changes and
    // additions here.  All rendering happens in this function.

    checkForGLErrors();

    // Clear the screen with the background colour.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Setup the model-view transformation matrix stack.
    transformStack().loadIdentity();
    checkForGLErrors();

    const float GLOBAL_X_SCALE = 0.8f;
    const float GLOBAL_Y_SCALE = 0.8f;
    const float BODY_X_SCALE = 120.0f;
    const float BODY_X_INV_SCALE = (float)(1/BODY_X_SCALE);
    const float BODY_Y_SCALE = 150.0f;
    const float BODY_Y_INV_SCALE = (float)(1/BODY_Y_SCALE);
    const float NECK_X_SCALE = 65.0f;
    const float NECK_Y_SCALE = 50.0f;
    const float BEAK_UP_X_SCALE = 28.0f;
    const float BEAK_UP_Y_SCALE = 5.0f;
    const float BEAK_DOWN_X_SCALE = 28.0f;
    const float BEAK_DOWN_Y_SCALE = 5.0f;
    const float ARM_X_SCALE = 20.0f;
    const float ARM_Y_SCALE = 70.0f;
    const float LEG_X_SCALE = 10.0f;
    const float LEG_X_INV_SCALE = (float)(1/LEG_X_SCALE);
    const float LEG_Y_SCALE = 60.0f;
    const float LEG_Y_INV_SCALE = (float)(1/LEG_Y_SCALE);
    const float FOOT_X_SCALE = 10.0f;
    const float FOOT_Y_SCALE = 40.0f;

    // Note that successive transformations are applied *before* the previous
    // ones.

    // Push the current transformation matrix on the stack
    transformStack().pushMatrix();
    transformStack().scale(GLOBAL_X_SCALE,GLOBAL_Y_SCALE);

    // Draw body
    transformStack().pushMatrix(); // Draw body push

    transformStack().translate(body_move_horizontal_trans,body_move_vertical_trans);
    transformStack().scale(BODY_X_SCALE,BODY_Y_SCALE);
    m_gl_state.setColor(1.0, 1.0, 0.0);
    m_unit_body.draw();
    transformStack().scale(BODY_X_INV_SCALE,BODY_Y_INV_SCALE);

    // Draw left leg and foot
    transformStack().pushMatrix();
    drawLeftLegFoot(LEG_X_SCALE,LEG_Y_SCALE,
                    LEG_X_INV_SCALE,LEG_Y_INV_SCALE,
                    FOOT_X_SCALE,FOOT_Y_SCALE);
    transformStack().popMatrix();

    // Draw right leg and foot
    transformStack().pushMatrix();
    drawRightLegFoot(LEG_X_SCALE,LEG_Y_SCALE,
                        LEG_X_INV_SCALE,LEG_Y_INV_SCALE,
                        FOOT_X_SCALE,FOOT_Y_SCALE);
    transformStack().popMatrix();

    // Draw left arm
    transformStack().pushMatrix();
    drawLeftArm(ARM_X_SCALE,ARM_Y_SCALE);
    transformStack().popMatrix();

    // Draw head, upper beak and lower beak
    transformStack().pushMatrix();
    drawNeck(NECK_X_SCALE,NECK_Y_SCALE,
             BEAK_UP_X_SCALE,BEAK_UP_Y_SCALE,
             BEAK_DOWN_X_SCALE,BEAK_DOWN_Y_SCALE,
             BODY_Y_SCALE);
    transformStack().popMatrix();

    transformStack().popMatrix(); // Draw body pop

    // Retrieve the previous state of the transformation stack
    transformStack().popMatrix();


    // Execute any GL functions that are in the queue just to be safe
    glFlush();
    checkForGLErrors();
}

void GLWidget::drawNeck(const float NECK_X_SCALE, const float NECK_Y_SCALE,
                         const float BEAK_UP_X_SCALE, const float BEAK_UP_Y_SCALE,
                         const float BEAK_DOWN_X_SCALE, const float BEAK_DOWN_Y_SCALE,
                         const float BODY_Y_SCALE)
{
    transformStack().pushMatrix();
    // position neck and joint together
    transformStack().translate(-2.5, BODY_Y_SCALE/2.5);

    transformStack().pushMatrix();
    transformStack().rotateInDegrees(neck_joint_angle);

    // Draw beak
    drawBeak(NECK_X_SCALE,BEAK_DOWN_X_SCALE,BEAK_DOWN_Y_SCALE,
                BEAK_UP_X_SCALE,BEAK_UP_Y_SCALE);

    transformStack().scale(NECK_X_SCALE,NECK_Y_SCALE); // 50,40
    transformStack().translate(0.0, 0.4);
    m_gl_state.setColor(0.0, 1.0, 1.0);
    m_unit_neck.draw();
    transformStack().popMatrix();

    transformStack().pushMatrix();
    drawJoint(1.0, NECK_Y_SCALE/5.0);
    transformStack().popMatrix();

    transformStack().popMatrix();
}
void GLWidget::drawBeak(const float NECK_X_SCALE,
                        const float BEAK_DOWN_X_SCALE, const float BEAK_DOWN_Y_SCALE,
                        const float BEAK_UP_X_SCALE, const float BEAK_UP_Y_SCALE)
{
    // Draw lower half beak
    transformStack().pushMatrix();
    transformStack().translate(-NECK_X_SCALE/2, beak_move_vertical_trans);
    transformStack().scale(BEAK_DOWN_X_SCALE,BEAK_DOWN_Y_SCALE);
    m_gl_state.setColor(0.0, 1.0, 0.0);
    m_unit_square.draw();
    transformStack().popMatrix();

    // Draw upper half beak
    transformStack().pushMatrix();
    transformStack().translate(-NECK_X_SCALE/2, 10.0+BEAK_DOWN_X_SCALE/2);
    transformStack().scale(BEAK_UP_X_SCALE,BEAK_UP_Y_SCALE);
    m_gl_state.setColor(0.0, 1.0, 0.0);
    m_unit_beakup.draw();
    transformStack().popMatrix();
}
void GLWidget::drawLeftArm(const float ARM_X_SCALE, const float ARM_Y_SCALE)
{
    transformStack().pushMatrix();
    // position left arm and joint together
    transformStack().translate(0.0, 30.0);

    transformStack().pushMatrix();
    transformStack().rotateInDegrees(leftarm_joint_angle);
    transformStack().scale(ARM_X_SCALE,ARM_Y_SCALE);
    transformStack().translate(0.0, -0.4);
    m_gl_state.setColor(0.0, 1.0, 0.0);
    m_unit_arm.draw();
    transformStack().popMatrix();

    transformStack().pushMatrix();
    drawJoint(0.0, 4.0);
    transformStack().popMatrix();

    transformStack().popMatrix();
}

void GLWidget::drawRightLegFoot(const float LEG_X_SCALE, const float LEG_Y_SCALE,
                                const float LEG_X_INV_SCALE, const float LEG_Y_INV_SCALE,
                                const float FOOT_X_SCALE, const float FOOT_Y_SCALE)
{
    transformStack().translate(30.0,-50.0);
    transformStack().rotateInDegrees(rightleg_joint_angle);
    transformStack().scale(LEG_X_SCALE,LEG_Y_SCALE);
    transformStack().translate(0.0, -0.5);
    m_gl_state.setColor(1.0, 0.0, 0.0);
    m_unit_square.draw();
    // since foot and joints as children of leg are already drawn,
    // to scale leg, need to inverse scale children of leg and scale everything back
    transformStack().scale(LEG_X_INV_SCALE,LEG_Y_INV_SCALE);

    transformStack().pushMatrix();
    drawJoint(0.0, LEG_Y_SCALE/2-4.0);
    transformStack().popMatrix();

    // Start drawing right foot and joint
    transformStack().pushMatrix();
    drawRightFoot(LEG_X_SCALE,LEG_Y_SCALE,FOOT_X_SCALE,FOOT_Y_SCALE);
    transformStack().popMatrix();
}
void GLWidget::drawRightFoot(const float LEG_X_SCALE, const float LEG_Y_SCALE,
                                const float FOOT_X_SCALE, const float FOOT_Y_SCALE)
{
    // position right foot and joint together
    transformStack().translate(LEG_X_SCALE/2-FOOT_X_SCALE/6, -LEG_Y_SCALE/2+FOOT_X_SCALE/2);

    // right foot
    transformStack().pushMatrix();
    transformStack().rotateInDegrees(rightfoot_joint_angle);
    transformStack().scale(FOOT_X_SCALE,FOOT_Y_SCALE);
    transformStack().translate(0.0, -0.5); // Move down so that the centre of rotation is at top
    m_gl_state.setColor(0.0, 1.0, 0.0);
    m_unit_foot.draw();
    transformStack().popMatrix();

    // right foot joint
    transformStack().pushMatrix();
    drawJoint(-4.0, 0.0);
    transformStack().popMatrix();
}
void GLWidget::drawLeftLegFoot(const float LEG_X_SCALE, const float LEG_Y_SCALE,
                                const float LEG_X_INV_SCALE, const float LEG_Y_INV_SCALE,
                                const float FOOT_X_SCALE, const float FOOT_Y_SCALE)
{
    transformStack().translate(-30.0,-50.0);
    transformStack().rotateInDegrees(leftleg_joint_angle);
    transformStack().scale(LEG_X_SCALE,LEG_Y_SCALE);
    transformStack().translate(0.0, -0.5);
    m_gl_state.setColor(1.0, 0.0, 0.0);
    m_unit_square.draw();
    // since foot and joint as children of leg are already drawn,
    // to scale leg, need to inverse scale children of leg and scale everything back
    transformStack().scale(LEG_X_INV_SCALE,LEG_Y_INV_SCALE);

    transformStack().pushMatrix();
    drawJoint(0.0, LEG_Y_SCALE/2-4.0);
    transformStack().popMatrix();

    // Start drawing left foot and joint
    transformStack().pushMatrix();
    drawLeftFoot(LEG_X_SCALE,LEG_Y_SCALE,FOOT_X_SCALE,FOOT_Y_SCALE);
    transformStack().popMatrix();
}
void GLWidget::drawLeftFoot(const float LEG_X_SCALE, const float LEG_Y_SCALE,
                                const float FOOT_X_SCALE, const float FOOT_Y_SCALE)
{
    // position left foot and joint together
    transformStack().translate(LEG_X_SCALE/2-FOOT_X_SCALE/6, -LEG_Y_SCALE/2+FOOT_X_SCALE/2);

    // left foot
    transformStack().pushMatrix();
    transformStack().rotateInDegrees(leftfoot_joint_angle);
    transformStack().scale(FOOT_X_SCALE,FOOT_Y_SCALE);
    transformStack().translate(0.0, -0.5); // Move down so that the centre of rotation is at top
    m_gl_state.setColor(0.0, 1.0, 0.0);
    m_unit_foot.draw();
    transformStack().popMatrix();

    // left foot joint
    transformStack().pushMatrix();
    drawJoint(-4.0, 0.0);
    transformStack().popMatrix();
}
void GLWidget::drawJoint(const float JOINT_X_TRANS, const float JOINT_Y_TRANS)
{
    transformStack().translate(JOINT_X_TRANS,JOINT_Y_TRANS);
    transformStack().scale(4.0,4.0);
    m_gl_state.setColor(0.0, 0.0, 1.0);
    m_unit_circle.draw();
}

