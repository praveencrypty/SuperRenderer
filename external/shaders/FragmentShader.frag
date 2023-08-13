#version 330 core

in vec4 ourColor;
out vec4 color;


void main()
{
    gl_Position = transform * vec4(0.5f * aPos * cos(timer), 1.0); // Mandotary Default Output variable 

    color = ourColor; // set the output variable to a dark-red color
}