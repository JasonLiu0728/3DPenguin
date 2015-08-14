/*************************************************************************
    CSC418/2504, Winter 20l5
    Assignment 1


    Instructions:
        See main.cpp for more instructions.

        This file contains the class for the main window of the program.
**************************************************************************/

#ifndef __MainWindow_h__
#define __MainWindow_h__

#include <QtGui/QtGui>
#include "GLWidget.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow()
    {
        // Create a GLWidget to hold the OpenGL viewport.
        m_gl_widget = new GLWidget();

        // Create a checkbox to turn animation on and off, and make it
        // call GLWidget::onPressAnimate when checked.
        m_animate_checkbox = new QCheckBox("Animate", this);
        connect(
            m_animate_checkbox, SIGNAL(stateChanged(int)),
            m_gl_widget, SLOT(onPressAnimate(int)));

        // Create a button to quit the program.
        m_quit_button = new QPushButton("Quit", this);
        connect(
            m_quit_button, SIGNAL(clicked(bool)),
            this, SLOT(onPressQuit(bool)));

        m_main_layout = new QVBoxLayout();
        m_main_layout->addWidget(m_gl_widget);


        // Create a slider to control the position, and make it call
        // GLWidget::setBodyHorizontalPosition when the slider value changes.
        body_horizontal_slider = create_joint_angle_slider(
	    "Body Horizontal", GLWidget::BODY_MOVE_HORIZONTAL_MIN, GLWidget::BODY_MOVE_HORIZONTAL_MAX);
        connect(
            body_horizontal_slider, SIGNAL(valueChanged(int)),
            m_gl_widget, SLOT(setBodyHorizontalPosition(int))
        );
        body_vertical_slider = create_joint_angle_slider(
	    "Body Vertical", GLWidget::BODY_MOVE_VERTICAL_MIN, GLWidget::BODY_MOVE_VERTICAL_MAX);
        connect(
            body_vertical_slider, SIGNAL(valueChanged(int)),
            m_gl_widget, SLOT(setBodyVerticalPosition(int))
        );
        // Create a slider to control the joint angle, and make it call
        // GLWidget::setJointAngle when the slider value changes.
        neck_slider = create_joint_angle_slider(
	    "Neck Joint", GLWidget::JOINT_MIN, GLWidget::JOINT_MAX);
        connect(
            neck_slider, SIGNAL(valueChanged(int)),
            m_gl_widget, SLOT(setNeckJointAngle(int))
        );
        beak_vertical_slider = create_joint_angle_slider(
	    "Beak Vertical", GLWidget::BEAK_MOVE_VERTICAL_MIN, GLWidget::BEAK_MOVE_VERTICAL_MAX);
        connect(
            beak_vertical_slider, SIGNAL(valueChanged(int)),
            m_gl_widget, SLOT(setBeakVerticalPosition(int))
        );
        leftarm_slider = create_joint_angle_slider(
	    "Left Arm Joint", GLWidget::JOINT_MIN, GLWidget::JOINT_MAX);
        connect(
            leftarm_slider, SIGNAL(valueChanged(int)),
            m_gl_widget, SLOT(setLeftArmJointAngle(int))
        );
        leftleg_slider = create_joint_angle_slider(
	    "Left Leg Joint", GLWidget::JOINT_MIN, GLWidget::JOINT_MAX);
        connect(
            leftleg_slider, SIGNAL(valueChanged(int)),
            m_gl_widget, SLOT(setLeftLegJointAngle(int))
        );
        leftfoot_slider = create_joint_angle_slider(
        "Left Foot Joint", GLWidget::FOOT_JOINT_MIN, GLWidget::FOOT_JOINT_MAX );
        connect(
                leftfoot_slider, SIGNAL(valueChanged(int)),
                m_gl_widget, SLOT(setLeftFootJointAngle(int))
                );
        rightleg_slider = create_joint_angle_slider(
        "Right Leg Joint", GLWidget::JOINT_MIN, GLWidget::JOINT_MAX );
        connect(
                rightleg_slider, SIGNAL(valueChanged(int)),
                m_gl_widget, SLOT(setRightLegJointAngle(int))
                );
        rightfoot_slider = create_joint_angle_slider(
        "Right Foot Joint", GLWidget::FOOT_JOINT_MIN, GLWidget::FOOT_JOINT_MAX );
        connect(
                rightfoot_slider, SIGNAL(valueChanged(int)),
                m_gl_widget, SLOT(setRightFootJointAngle(int))
                );

        m_main_layout->addWidget(m_animate_checkbox);
        m_main_layout->addWidget(m_quit_button);
        setLayout(m_main_layout);

        body_horizontal_slider->setValue(0);
        body_vertical_slider->setValue(0);
        neck_slider->setValue(0);
        //beak_vertical_slider->setValue(20);
        leftarm_slider->setValue(0);
        leftleg_slider->setValue(0);
        leftfoot_slider->setValue(-90);
        rightleg_slider->setValue(0);
        rightfoot_slider->setValue(-90);
        setWindowTitle("Yuxi Liu 997930379");
    }

public slots:
    void onPressQuit(bool)
    {
        exit(0);
    }

private:
    QSlider *create_joint_angle_slider(
	const char *label, int min_angle, int max_angle)
    {
        QSlider *slider = new QSlider(Qt::Horizontal, this);
        slider->setRange(min_angle, max_angle);
        slider->setSingleStep(1);
        slider->setPageStep(5);
        slider->setTickInterval(5);
        slider->setTickPosition(QSlider::TicksBelow);

	QBoxLayout *layout = new QHBoxLayout();
	layout->addWidget(new QLabel(label));
	layout->addWidget(slider);
	m_main_layout->addLayout(layout);

        return slider;
    }

    GLWidget *m_gl_widget;
    QCheckBox *m_animate_checkbox;
    QPushButton *m_quit_button;
    QSlider *body_horizontal_slider;
    QSlider *body_vertical_slider;
    QSlider *neck_slider;
    QSlider *beak_vertical_slider;
    QSlider *leftarm_slider;
    QSlider *leftleg_slider;
    QSlider *leftfoot_slider;
    QSlider *rightleg_slider;
    QSlider *rightfoot_slider;
    QVBoxLayout *m_main_layout;
};

#endif
