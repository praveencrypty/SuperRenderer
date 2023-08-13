#version 330 core
layout(location = 0) in vec3 aPos; // the position variable has attribute index 0  
layout(location = 1) in vec3 aCol; // the color variable has attribute index 1  


out vec4 ourColor; // specify a color output to the fragment shader

void main()
{
    gl_Position = transform * vec4(0.5f * aPos * cos(timer), 1.0); // Mandotary Default Output variable 

    ourColor = aCol; // set the output variable to a dark-red color
}