
/****************************************************************************************

    CarGL (Objects.cpp)

    Grado en Ingeniería Multimedia.
    Práctica de Gráficos por Computador.
    OpenGL con Shaders.
  ---------------------------------------------------------------------------------------

    2012 - 2022 (C) Juan Antonio Puchol García (puchol@dccia.ua.es)


*****************************************************************************************/

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Objects.h"
#include <GL/glui.h>

#include "load3ds.c"

// Variable para inicializar los vectores correpondientes con los valores iniciales
GLfloat light0_ambient_c[4]  = {   0.2f,   0.2f,  0.2f, 1.0f };
GLfloat light0_diffuse_c[4]  = {   0.8f,   0.8f,  0.8f, 1.0f };
GLfloat light0_specular_c[4] = {   1.0f,   1.0f,  1.0f, 1.0f };
GLfloat light0_position_c[4] = {-100.0f, 100.0f, 50.0f, 1.0f };

GLfloat light1_ambient_c[4]  = {   0.2f,   0.2f,  0.2f, 1.0f };
GLfloat light1_diffuse_c[4]  = {   0.8f,   0.8f,  0.8f, 1.0f };
GLfloat light1_specular_c[4] = {   1.0f,   1.0f,  1.0f, 1.0f };
GLfloat light1_position_c[4] = {   0.0f, 100.0f,  0.0f, 1.0f };

GLfloat mat_ambient_c[4]    = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat mat_diffuse_c[4]    = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat mat_specular_c[4]   = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat mat_shininess_c[1] = { 100.0f };

// Matriz de 4x4 = (I)
float view_rotate_c[16] = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };
float view_position_c[3] = { 0.0, -2.0, -9.0 };

float coloresc_c[2][4] = { {0.8, 0.5, 0.0, 1.0}, {0.5, 0.5, 0.5, 1.0}}; // Color del coche
float coloresr_c[2][4] = { {0.3, 0.3, 0.3, 1.0}, {1.0, 1.0, 1.0, 1.0}}; // Color de la carretera

//************************************************************** Variables de clase

TEscena escena;
TGui    gui;

//************************************************************** Clase TPrimitiva

TPrimitiva::TPrimitiva(int DL, int t)
{

    ID   = DL;
    tipo = t;

    sx = sy = sz = 1;
    rx = ry = rz = 0;
	switch (tipo) {
		case CARRETERA_ID: {  // Creación de la carretera
		    tx = ty = tz = 0;

            memcpy(colores, coloresr_c, 8*sizeof(float));

            //************************ Cargar modelos 3ds ***********************************
            // formato 8 floats por vértice (x, y, z, A, B, C, u, v)
            modelo0 = Load3DS("../../Modelos/Base.3ds", &num_vertices0);
            modelo1 = Load3DS("../../Modelos/Lineas.3ds", &num_vertices1);

            break;
		}
		case EDIFICIO_ID: {  // Creación del edificio

            tx = -10.2;
            tz = -22.6;
            ty = 0.25;

            memcpy(colores, coloresr_c, 8*sizeof(float));

            //************************ Cargar modelos 3ds ***********************************
            // formato 8 floats por vértice (x, y, z, A, B, C, u, v)
            modelo0 = Load3DS("../../Modelos/Edificio.3ds", &num_vertices0);
            modelo1 = NULL;
            break;
		}
		case SEMG_ID: {
		    tx = 6.7;
		    ty = 0.26;
		    tz = 9.7;
		    memcpy(colores, coloresr_c, 8*sizeof(float));

		    modelo0 = Load3DS("../../Modelos/SemaforoGrande.3ds", &num_vertices0);
		    modelo1 = NULL;
		    break;
		}
		case SEMP_ID: {
		    tx =  -3.3;
		    ty = 0.26;
		    tz = 5.3;
		    memcpy(colores, coloresr_c, 8*sizeof(float));

		    modelo0 = Load3DS("../../Modelos/SemaforoPeatones.3ds", &num_vertices0);
		    modelo1 = NULL;
		    break;
		}
		case VALLA2_ID: {
		    ty = 0.7;
		    tx = 23.16;
		    tz = -4.5;
		    memcpy(colores, coloresr_c, 8*sizeof(float));

		    modelo0 = Load3DS("../../Modelos/Valla2.3ds", &num_vertices0);
		    modelo1 = NULL;
		    break;
		}
		case VALLA3_ID: {
		    ty = 0.7;
		    tx = 20.16;
		    tz = -4.5;
		    memcpy(colores, coloresr_c, 8*sizeof(float));

		    modelo0 = Load3DS("../../Modelos/Valla3.3ds", &num_vertices0);
		    modelo1 = NULL;
		    break;
		}
		case FAROLA_ID: {
		    ty = 0.26;
		    tx = 21.91;
		    tz = -4.5;
		    memcpy(colores, coloresr_c, 8*sizeof(float));

		    modelo0 = Load3DS("../../Modelos/Farola.3ds", &num_vertices0);
		    modelo1 = NULL;
		    break;
		}
		case PAPELERA_ID: {
		    tx = 13.1;
		    tz = 11.4929;
		    ty = 0.26;
		    ry = 45;
		    memcpy(colores, coloresr_c, 8*sizeof(float));

		    modelo0 = Load3DS("../../Modelos/Papelera.3ds", &num_vertices0);
		    modelo1 = NULL;
		    break;
		}
		case BANCO_ID: {
		    tx = -9.2;
		    tz = -8.4929;
		    ty = 0.26;
		    memcpy(colores, coloresr_c, 8*sizeof(float));

		    modelo0 = Load3DS("../../Modelos/Banco.3ds", &num_vertices0);
		    modelo1 = NULL;
		    break;
		}
		case COCHE_ID: { // Creación del coche

		    tx =  -0.8;
		    ty =  0.48;
		    tz =  15;
		    rr =  0.0;

		    memcpy(colores, coloresc_c, 8*sizeof(float));

            //************************ Cargar modelos 3ds ***********************************
            // formato 8 floats por vértice (x, y, z, A, B, C, u, v)
            modelo0 = Load3DS("../../Modelos/CocheSR.3ds", &num_vertices0);
            modelo1 = Load3DS("../../Modelos/Rueda.3ds", &num_vertices1);
            break;
		}
	} // switch
}

void __fastcall TPrimitiva::Render(int seleccion, bool reflejo)
{
    glm::mat4   modelMatrix;
    glm::mat4   modelViewMatrix;
    switch (tipo) {

        case CARRETERA_ID: {
            if (escena.show_road) {
                // Cálculo de la ModelView
                modelMatrix     = glm::mat4(1.0f); // matriz identidad
                modelViewMatrix = escena.viewMatrix * modelMatrix;
                // Envía nuestra ModelView al Vertex Shader
                glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

                // Pintar la carretera
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0+3);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices0);

                // Pintar las líneas
                glUniform4fv(escena.uColorLocation, 1, colores[1]);

                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo1);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo1+3);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices1);


            }
            break;
        } // case CARRETERA_ID:
        case EDIFICIO_ID: {
            if (escena.show_road) {
                // Cálculo de la ModelView
                modelMatrix     = glm::mat4(1.0f); // matriz identidad

                modelMatrix     = glm::translate(modelMatrix, glm::vec3(tx, ty, tz));
                modelMatrix     = glm::rotate(modelMatrix, (float) glm::radians(ry), glm::vec3(0,1,0)); // rotación alrededor del eje y en radianes

                modelViewMatrix = escena.viewMatrix * modelMatrix;
                // Envía nuestra ModelView al Vertex Shader
                glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

                // Pintar la carretera
                glUniform4fv(escena.uColorLocation, 1, colores[0]);
                //                   Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0+3);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
            }
            break;
        }
        case SEMG_ID: {
            modelMatrix     = glm::mat4(1.0f); // matriz identidad
            modelMatrix     = glm::translate(modelMatrix, glm::vec3(tx, ty, tz));
            modelMatrix     = glm::rotate(modelMatrix, (float) glm::radians(ry), glm::vec3(0,1,0));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glUniform4fv(escena.uColorLocation, 1, colores[0]);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0+3);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
            break;
        }
        case SEMP_ID: {
            modelMatrix     = glm::mat4(1.0f); // matriz identidad
            modelMatrix     = glm::translate(modelMatrix, glm::vec3(tx, ty, tz));
            modelMatrix     = glm::rotate(modelMatrix, (float) glm::radians(ry), glm::vec3(0,1,0));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glUniform4fv(escena.uColorLocation, 1, colores[0]);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0+3);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
            break;
        }
        case VALLA2_ID: {
            modelMatrix     = glm::mat4(1.0f); // matriz identidad
            modelMatrix     = glm::translate(modelMatrix, glm::vec3(tx, ty, tz));
            modelMatrix     = glm::rotate(modelMatrix, (float) glm::radians(ry), glm::vec3(0,1,0));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glUniform4fv(escena.uColorLocation, 1, colores[0]);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0+3);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
            break;
        }
        case VALLA3_ID: {
            modelMatrix     = glm::mat4(1.0f); // matriz identidad
            modelMatrix     = glm::translate(modelMatrix, glm::vec3(tx, ty, tz));
            modelMatrix     = glm::rotate(modelMatrix, (float) glm::radians(ry), glm::vec3(0,1,0));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glUniform4fv(escena.uColorLocation, 1, colores[0]);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0+3);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
            break;
        }
        case FAROLA_ID: {
                        modelMatrix     = glm::mat4(1.0f); // matriz identidad
            modelMatrix     = glm::translate(modelMatrix, glm::vec3(tx, ty, tz));
            modelMatrix     = glm::rotate(modelMatrix, (float) glm::radians(ry), glm::vec3(0,1,0));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glUniform4fv(escena.uColorLocation, 1, colores[0]);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0+3);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
            break;
        }
        case PAPELERA_ID: {
            modelMatrix     = glm::mat4(1.0f); // matriz identidad
            modelMatrix     = glm::translate(modelMatrix, glm::vec3(tx, ty, tz));
            modelMatrix     = glm::rotate(modelMatrix, (float) glm::radians(ry), glm::vec3(0,1,0));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glUniform4fv(escena.uColorLocation, 1, colores[0]);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0+3);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
            break;
        }
        case BANCO_ID: {
            modelMatrix     = glm::mat4(1.0f); // matriz identidad
            modelMatrix     = glm::translate(modelMatrix, glm::vec3(tx, ty, tz));
            modelMatrix     = glm::rotate(modelMatrix, (float) glm::radians(ry), glm::vec3(0,1,0));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glUniform4fv(escena.uColorLocation, 1, colores[0]);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0+3);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
            break;
        }
         // case CARRETERA_ID:
        case COCHE_ID: {
            if (escena.show_car) {
                glUniform4fv(escena.uColorLocation, 1, (const GLfloat *) colores[0]);
                // Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0+3);

                // Cálculo de la matriz modelo
                modelMatrix     = glm::mat4(1.0f); // matriz identidad
                modelMatrix     = glm::translate(modelMatrix,glm::vec3(tx, ty, tz));

                modelViewMatrix = escena.viewMatrix * modelMatrix;

                // Envía nuestra ModelView al Vertex Shader
                glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
            }


            if (escena.show_wheels)
            {
                glUniform4fv(escena.uColorLocation, 1, (const GLfloat *) colores[1]);
                // Asociamos los vértices y sus normales
                glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo1);
                glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo1+3);

                // RUEDA Delantera Izquierda : Cálculo de la matriz modelo

                modelMatrix     = glm::mat4(1.0f); // matriz identidad

                modelMatrix     = glm::translate(modelMatrix, glm::vec3(tx-0.94, ty, tz));
                modelMatrix     = glm::rotate(modelMatrix, (float) glm::radians(rr), glm::vec3(1,0,0));      // en radianes
                modelMatrix     = glm::rotate(modelMatrix, (float) glm::radians(180.0), glm::vec3(0,0,1));   // en radianes

                modelViewMatrix = escena.viewMatrix * modelMatrix;

                // Envia nuestra ModelView al Vertex Shader
                glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices1);

                // RUEDA Trasera Izquierda : Cálculo de la matriz modelo
                modelMatrix     = glm::mat4(1.0f); // matriz identidad
                modelMatrix     = glm::translate(modelMatrix, glm::vec3(tx-0.94, ty, tz-3.2232));
                modelMatrix     = glm::rotate(modelMatrix, (float) glm::radians(rr), glm::vec3(1,0,0));
                modelMatrix     = glm::rotate(modelMatrix, (float) glm::radians(180.0), glm::vec3(0,0,1));   // en radianes

                modelViewMatrix = escena.viewMatrix * modelMatrix;

                // Envia nuestra ModelView al Vertex Shader
                glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices1);

                // RUEDA Delantera Derecha : Cálculo de la matriz modelo
                modelMatrix     = glm::mat4(1.0f); // matriz identidad

                modelMatrix     = glm::translate(modelMatrix, glm::vec3(tx+0.94, ty, tz));
                modelMatrix     = glm::rotate(modelMatrix, (float) glm::radians(rr), glm::vec3(1,0,0));      // en radianes


                modelViewMatrix = escena.viewMatrix * modelMatrix;

                // Envia nuestra ModelView al Vertex Shader
                glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices1);

                // RUEDA Trasera Derecha : Cálculo de la matriz modelo
                modelMatrix     = glm::mat4(1.0f); // matriz identidad
                modelMatrix     = glm::translate(modelMatrix, glm::vec3(tx+0.94, ty, tz-3.2232));
                modelMatrix     = glm::rotate(modelMatrix, (float) glm::radians(rr), glm::vec3(1,0,0));

                modelViewMatrix = escena.viewMatrix * modelMatrix;

                // Envia nuestra ModelView al Vertex Shader
                glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices1);

            }
            break;
        } // case COCHE_ID:
    }// switch
}

//************************************************************** Clase TEscena

TEscena::TEscena() {

    seleccion = 1;
    num_objects = 0;
    num_cars = 0;

    show_car = 1;
    show_wheels = 1;
    show_road = 1;

    // live variables usadas por GLUI en TGui
    wireframe = 0;
    z_buffer = 1;
    culling = 0;

    scale = 100.0;
    xy_aspect = 1;
    last_x = 0;
    last_y = 0;

    memcpy(view_position, view_position_c, 3*sizeof(float));
    memcpy(view_rotate, view_rotate_c, 16*sizeof(float));

    memcpy(light0_ambient, light0_ambient_c, 4*sizeof(float));

    memcpy(light0_ambient, light0_ambient_c, 4*sizeof(float));
    memcpy(light0_diffuse, light0_diffuse_c, 4*sizeof(float));
    memcpy(light0_specular, light0_specular_c, 4*sizeof(float));
    memcpy(light0_position, light0_position_c, 4*sizeof(float));

    memcpy(light1_ambient, light1_ambient_c, 4*sizeof(float));
    memcpy(light1_diffuse, light1_diffuse_c, 4*sizeof(float));
    memcpy(light1_specular, light1_specular_c, 4*sizeof(float));
    memcpy(light1_position, light1_position_c, 4*sizeof(float));

    memcpy(mat_ambient, mat_ambient_c, 4*sizeof(float));
    memcpy(mat_diffuse, mat_diffuse_c, 4*sizeof(float));
    memcpy(mat_specular, mat_specular_c, 4*sizeof(float));
    memcpy(mat_shininess, mat_shininess_c, 1*sizeof(float));
}

void __fastcall TEscena::InitGL()
{
    int tx, ty, tw, th;

    // Habilita el z_buffer
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    // Inicialización de GLEW
    std::cout << "Inicializando GLEW" << std::endl << std::endl;
    if(glewInit() != GLEW_OK)
        throw std::runtime_error("glewInit failed");

    // print out some info about the graphics drivers
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "Vendedor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;

    // Carga de los Shaders
    std::cout << std::endl << "Cargando Shaders" << std::endl;

    Shader shader;

    std::vector<GLuint> shaders;
    shaders.push_back(shader.LoadShader("../../Shaders/VertexShader.glsl", GL_VERTEX_SHADER));
    //std::cout << "Vertex Shader: " << shader.ReturnShaderID() << std::endl;
    shaders.push_back(shader.LoadShader("../../Shaders/FragmentShader.glsl", GL_FRAGMENT_SHADER));
    //std::cout << "Fragment Shader: " << shader.ReturnShaderID() << std::endl;
    shaderProgram = new Program(shaders);

    //std::cout << "Shader Program: " << shaderProgram->ReturnProgramID() << std::endl;

    glUseProgram(shaderProgram->ReturnProgramID());
    //glValidateProgram(shaderProgram->ReturnProgramID());

    aPositionLocation=shaderProgram->attrib(A_POSITION);
    aNormalLocation=shaderProgram->attrib(A_NORMAL);

    uProjectionMatrixLocation=shaderProgram->uniform(U_PROJECTIONMATRIX);
    uMVMatrixLocation=shaderProgram->uniform(U_MVMATRIX);
    uVMatrixLocation=shaderProgram->uniform(U_VMATRIX);
    uColorLocation=shaderProgram->uniform(U_COLOR);
    uLuz0Location=shaderProgram->uniform(U_LUZ0);

    /*
    std::cout << "a_Position Location: " << aPositionLocation << std::endl;
    std::cout << "a_Normal Location: " << aNormalLocation << std::endl;

    std::cout << "u_ProjectionMatrix Location: " << uProjectionMatrixLocation << std::endl;
    std::cout << "u_MVMatrix Location: " << uMVMatrixLocation << std::endl;
    std::cout << "u_VMatrix Location: " << uVMatrixLocation << std::endl;
    std::cout << "u_Color Location: " << uColorLocation << std::endl;
    std::cout << "u_Luz0 Location: " << uLuz0Location << std::endl;
    */

    // Habilitamos el paso de attributes
    glEnableVertexAttribArray(aPositionLocation);
    glEnableVertexAttribArray(aNormalLocation);

    // Estableciendo la matriz de proyección perspectiva
    GLUI_Master.get_viewport_area( &tx, &ty, &tw, &th );
    xy_aspect = (float)tw / (float)th;
    projectionMatrix = glm::perspective(45.0f, xy_aspect, 0.1f, 1000.0f);
    glUniformMatrix4fv(uProjectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
}


/************************** TEscena::AddCar(TPrimitiva *car) *****************/

void __fastcall TEscena::AddCar(TPrimitiva *car)
{
    cars[num_cars] = car;
    num_cars++;
}

/******************** TEscena::AddObject(TPrimitiva *object) *****************/

void __fastcall TEscena::AddObject(TPrimitiva *object)
{
    objects[num_objects] = object;
    num_objects++;
}

/******************** TPrimitiva *TEscena::GetCar(int id) ********************/

TPrimitiva __fastcall *TEscena::GetCar(int id)
{
    TPrimitiva *p=NULL;

    for (int i=0; i<num_cars; i++)
    {
        if (cars[i]->ID==id)
        {
            p = cars[i];
        }

    }
    return(p);
}

/******************** TEscena::RenderCars() **********************************/

void __fastcall TEscena::RenderCars(bool reflejo) {

    for (int i=0; i<num_cars; i++)
    {
        cars[i]->Render(seleccion, reflejo);
    }
}

/******************** TEscena::RenderCars() **********************************/

void __fastcall TEscena::RenderObjects(bool reflejo) {

    for (int i=0; i<num_objects; i++)
    {
        objects[i]->Render(seleccion, reflejo);
    }
}

/***************************************** TEscena::Render() *****************/

void __fastcall TEscena::Render()
{
    glm::mat4 rotateMatrix;

    glClearColor(0.0, 0.7, 0.9, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Cálculo de la vista (cámara)
    viewMatrix      = glm::mat4(1.0f);
    rotateMatrix    = glm::make_mat4(view_rotate);
    viewMatrix      = glm::translate(viewMatrix,glm::vec3(view_position[0], view_position[1], view_position[2]));
    viewMatrix      = viewMatrix*rotateMatrix;
    viewMatrix      = glm::scale(viewMatrix,glm::vec3(scale/100.0, scale/100.0, scale/100.0));

    glUniform1i(uLuz0Location, gui.light0_enabled);
    glUniformMatrix4fv(uVMatrixLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix)); // Para la luz matrix view pero sin escalado!

    // Dibujar carretera y objetos
    RenderObjects(seleccion);

    // Dibujar coches
    RenderCars(seleccion);

    glutSwapBuffers();
}

// Selecciona un objeto a través del ratón
void __fastcall TEscena::Pick3D(int mouse_x, int mouse_y)
{
}

double generarNumeroAleatorio() {
    return static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX);
}

// Crea todo el escenario
void __fastcall TEscena::CrearEscenario()
{
    TPrimitiva *road = new TPrimitiva(CARRETERA_ID, CARRETERA_ID);
    TPrimitiva *car1 = new TPrimitiva(1, COCHE_ID);
    TPrimitiva *car2 = new TPrimitiva(2, COCHE_ID);
    TPrimitiva *edificio1 = new TPrimitiva(EDIFICIO_ID, EDIFICIO_ID);
    TPrimitiva *edificio2 = new TPrimitiva(EDIFICIO_ID, EDIFICIO_ID);
    TPrimitiva *edificio3 = new TPrimitiva(EDIFICIO_ID, EDIFICIO_ID);
    TPrimitiva *edificio4 = new TPrimitiva(EDIFICIO_ID, EDIFICIO_ID);
    TPrimitiva *edificio5 = new TPrimitiva(EDIFICIO_ID, EDIFICIO_ID);
    TPrimitiva *edificio6 = new TPrimitiva(EDIFICIO_ID, EDIFICIO_ID);
    TPrimitiva *edificio7 = new TPrimitiva(EDIFICIO_ID, EDIFICIO_ID);
    TPrimitiva *edificio8 = new TPrimitiva(EDIFICIO_ID, EDIFICIO_ID);
    TPrimitiva *semG0 = new TPrimitiva(SEMG_ID, SEMG_ID);
    TPrimitiva *semG1 = new TPrimitiva(SEMG_ID, SEMG_ID);
    TPrimitiva *semG2 = new TPrimitiva(SEMG_ID, SEMG_ID);
    TPrimitiva *semG3 = new TPrimitiva(SEMG_ID, SEMG_ID);
    TPrimitiva *semP0 = new TPrimitiva(SEMP_ID, SEMP_ID);
    TPrimitiva *semP1 = new TPrimitiva(SEMP_ID, SEMP_ID);
    TPrimitiva *semP2 = new TPrimitiva(SEMP_ID, SEMP_ID);
    TPrimitiva *semP3 = new TPrimitiva(SEMP_ID, SEMP_ID);
    TPrimitiva *banco0 = new TPrimitiva(BANCO_ID, BANCO_ID);
    TPrimitiva *banco1 = new TPrimitiva(BANCO_ID, BANCO_ID);
    TPrimitiva *banco2 = new TPrimitiva(BANCO_ID, BANCO_ID);
    TPrimitiva *banco3 = new TPrimitiva(BANCO_ID, BANCO_ID);
    TPrimitiva *banco4 = new TPrimitiva(BANCO_ID, BANCO_ID);
    TPrimitiva *banco5 = new TPrimitiva(BANCO_ID, BANCO_ID);
    TPrimitiva *banco6 = new TPrimitiva(BANCO_ID, BANCO_ID);
    TPrimitiva *banco7 = new TPrimitiva(BANCO_ID, BANCO_ID);

    std::srand(std::time(0));

    car2->tz = -12;
    car2->colores[0][0] = 0.1;
    car2->colores[0][1] = 0.4;
    car2->colores[0][2] = 0.9;
    car2->colores[0][3] = 1.0;

    //manzana1
    for(int i = 0; i<3; i++){
        edificio1->colores[0][i] = generarNumeroAleatorio();
    }

    edificio2->ry = edificio1->ry - 90;
    edificio2->tz = edificio1->tz + 10.7474;
    for(int i = 0; i<3; i++){
        edificio2->colores[0][i] = generarNumeroAleatorio();
    }

    //manzana2
    edificio3->ry = 90;
    edificio3->tx = edificio3->tx - 10.7632;
    edificio3->tz = edificio3->tz + 34.7654;
    for(int i = 0; i<3; i++){
        edificio3->colores[0][i] = generarNumeroAleatorio();
    }


    edificio4->tz = edificio3->tz;
    edificio4->tx = edificio3->tx + 10.7474;
    for(int i = 0; i<3; i++){
        edificio4->colores[0][i] = generarNumeroAleatorio();
    }

    //manzana3
    edificio5->ry = edificio3->ry + 90;
    edificio5->tz = edificio3->tz + 10.7632;
    edificio5->tx = edificio3->tx + 34.7654;
    for(int i = 0; i<3; i++){
        edificio5->colores[0][i] = generarNumeroAleatorio();
    }

    edificio6->ry = edificio5->ty + 90;
    edificio6->tz = edificio5->tz - 10.7474;
    edificio6->tx = edificio5->tx;
    for(int i = 0; i<3; i++){
        edificio6->colores[0][i] = generarNumeroAleatorio();
    }

    //manzana4
    edificio7->ry = edificio5->ty - 90;
    edificio7->tx = edificio5->tx + 10.7474;
    edificio7->tz = edificio5->tz - 34.7654;
    for(int i = 0; i<3; i++){
        edificio7->colores[0][i] = generarNumeroAleatorio();
    }

    edificio8->ry = edificio7->ry - 90;
    edificio8->tx = edificio7->tx - 10.7474;
    edificio8->tz = edificio7->tz + 0.1;
    for(int i = 0; i<3; i++){
        edificio8->colores[0][i] = generarNumeroAleatorio();
    }

    semG0->colores[0][0] = 0.1;
    semG0->colores[0][1] = 0.7;
    semG0->colores[0][2] = 0.2;

    semG1->tx = semG1->tx + 4.6;
    semG1->tz = semG1->tz - 15;
    semG1->ry = semG0->ry + 90;
    semG1->colores[0][0] = 0.1;
    semG1->colores[0][1] = 0.7;
    semG1->colores[0][2] = 0.2;

    semG2->tx = semG1->tx - 15;
    semG2->tz = semG1->tz - 4.6;
    semG2->ry = semG1->ry + 90;
    semG2->colores[0][0] = 0.1;
    semG2->colores[0][1] = 0.7;
    semG2->colores[0][2] = 0.2;

    semG3->tx = semG2->tx - 4.6;
    semG3->tz = semG2->tz + 15;
    semG3->ry = semG2->ry + 90;
    semG3->colores[0][0] = 0.1;
    semG3->colores[0][1] = 0.7;
    semG3->colores[0][2] = 0.2;

    semP0->colores[0][0] = 0.1;
    semP0->colores[0][1] = 0.7;
    semP0->colores[0][2] = 0.2;

    semP1->tx = semP0->tx + 10.3;
    semP1->ry = semP0->ry + 90;
    semP1->colores[0][0] = 0.1;
    semP1->colores[0][1] = 0.7;
    semP1->colores[0][2] = 0.2;

    semP2->tz = semP1->tz - 10.3;
    semP2->tx = semP1->tx;
    semP2->ry = semP1->ry + 90;
    semP2->colores[0][0] = 0.1;
    semP2->colores[0][1] = 0.7;
    semP2->colores[0][2] = 0.2;

    semP3->tz = semP2->tz;
    semP3->tx = semP2->tx - 10.3;
    semP3->ry = semP2->ry + 90;
    semP3->colores[0][0] = 0.1;
    semP3->colores[0][1] = 0.7;
    semP3->colores[0][2] = 0.2;

    banco0->colores[0][0] = 0.8;
    banco0->colores[0][1] = 0.2;
    banco0->colores[0][2] = 0.4;

    /*
    tx = -9.2;
    tz = -8.4929;
    */

    banco1->colores[0][0] = 0.8;
    banco1->colores[0][1] = 0.2;
    banco1->colores[0][2] = 0.4;
    banco1->ry = -90;
    banco1->tx = -8.7;
    banco1->tz = -11;

    banco2->colores[0][0] = 0.8;
    banco2->colores[0][1] = 0.2;
    banco2->colores[0][2] = 0.4;
    banco2->ry = -90;
    banco2->tx = 10.4;
    banco2->tz = -11;

    banco3->colores[0][0] = 0.8;
    banco3->colores[0][1] = 0.2;
    banco3->colores[0][2] = 0.4;
    banco3->ry = 180;
    banco3->tx = 12.6;
    banco3->tz = -10.5;

    banco4->colores[0][0] = 0.8;
    banco4->colores[0][1] = 0.2;
    banco4->colores[0][2] = 0.4;
    //banco4->ry = ;
    banco4->tx = -9;
    banco4->tz = 10.9;

    banco5->colores[0][0] = 0.8;
    banco5->colores[0][1] = 0.2;
    banco5->colores[0][2] = 0.4;
    banco5->ry = 90;
    banco5->tx = -7;
    banco5->tz = 10.9;

    banco6->colores[0][0] = 0.8;
    banco6->colores[0][1] = 0.2;
    banco6->colores[0][2] = 0.4;
    banco6->ry = 180;
    banco6->tx = 12.6;
    banco6->tz = 9;

    banco7->colores[0][0] = 0.8;
    banco7->colores[0][1] = 0.2;
    banco7->colores[0][2] = 0.4;
    banco7->ry = 90;
    banco7->tx = 12.6;
    banco7->tz = 11;

    // Añadir objetos
    AddObject(road);
    AddObject(edificio1);
    AddObject(edificio2);
    AddObject(edificio3);
    AddObject(edificio4);
    AddObject(edificio5);
    AddObject(edificio6);
    AddObject(edificio7);
    AddObject(edificio8);
    AddObject(semG0);
    AddObject(semG1);
    AddObject(semG2);
    AddObject(semG3);
    AddObject(semP0);
    AddObject(semP1);
    AddObject(semP2);
    AddObject(semP3);
    AddObject(banco0);
    AddObject(banco1);
    AddObject(banco2);
    AddObject(banco3);
    AddObject(banco4);
    AddObject(banco5);
    AddObject(banco6);
    AddObject(banco7);

    // Añadir coches
    AddCar(car1);
    AddCar(car2);

    //agrego los objetos repetidos con fors
    TPrimitiva *valla20[2];
    for(int i = 0; i<2; i++){
        valla20[i] = new TPrimitiva(VALLA2_ID, VALLA2_ID);

        valla20[i]->colores[0][0] = 0.5;
        valla20[i]->colores[0][1] = 0.2;
        valla20[i]->colores[0][2] = 0.2;

        if(i > 0){
            valla20[i]->tz = valla20[0]->tz + 9.36;
        }

        AddObject(valla20[i]);
    }

    TPrimitiva *valla21[2];
    for(int i = 0; i<2; i++){
        valla21[i] = new TPrimitiva(VALLA2_ID, VALLA2_ID);

        valla21[i]->colores[0][0] = 0.5;
        valla21[i]->colores[0][1] = 0.2;
        valla21[i]->colores[0][2] = 0.2;

        if(i == 0){
            valla21[i]->tx = -20;
        }else if(i > 0){
            valla21[i]->tx = valla21[0]->tx;
            valla21[i]->tz = valla21[0]->tz + 9.36;
        }

        AddObject(valla21[i]);
    }

    TPrimitiva *valla22[2];
    for(int i = 0; i<2; i++){
        valla22[i] = new TPrimitiva(VALLA2_ID, VALLA2_ID);

        valla22[i]->ry = valla22[i]->ry + 90;
        valla22[i]->colores[0][0] = 0.5;
        valla22[i]->colores[0][1] = 0.2;
        valla22[i]->colores[0][2] = 0.2;

        /*
            tx = 23.16;
		    tz = -4.5;
        */

        if(i == 0){
            valla22[i]->tx = -3.1;
            valla22[i]->tz = -21.42;
        }else{
            valla22[i]->tz = valla22[0]->tz;
            valla22[i]->tx = valla22[0]->tx + 9.4;
        }

        AddObject(valla22[i]);
    }

    TPrimitiva *valla23[2];
    for(int i = 0; i<2; i++){
        valla23[i] = new TPrimitiva(VALLA2_ID, VALLA2_ID);

        valla23[i]->ry = valla23[i]->ry + 90;
        valla23[i]->colores[0][0] = 0.5;
        valla23[i]->colores[0][1] = 0.2;
        valla23[i]->colores[0][2] = 0.2;

        /*
            tx = 23.16;
		    tz = -4.5;
        */

        if(i == 0){
            valla23[i]->tx = -3.1;
            valla23[i]->tz = 21.42;
        }else{
            valla23[i]->tz = valla23[0]->tz;
            valla23[i]->tx = valla23[0]->tx + 9.4;
        }

        AddObject(valla23[i]);
    }

    TPrimitiva *valla30[6];
    for(int i = 0; i<6; i++){
        valla30[i] = new TPrimitiva(VALLA3_ID, VALLA3_ID);

        valla30[i]->colores[0][0] = 0.5;
        valla30[i]->colores[0][1] = 0.2;
        valla30[i]->colores[0][2] = 0.2;

        if(i >= 1 && i <= 2){
            valla30[i]->tx = valla30[i-1]->tx - 3.5;
        }else if(i == 3){
            valla30[i]->tz = valla30[0]->tz + 9.36;
        }else if(i > 3){
            valla30[i]->tz = valla30[i-1]->tz;
            valla30[i]->tx = valla30[i-1]->tx - 3.5;
        }

        AddObject(valla30[i]);
    }

    TPrimitiva *valla31[6];
    for(int i = 0; i<6; i++){
        valla31[i] = new TPrimitiva(VALLA3_ID, VALLA3_ID);

        valla31[i]->colores[0][0] = 0.5;
        valla31[i]->colores[0][1] = 0.2;
        valla31[i]->colores[0][2] = 0.2;

        /*
        tx = 20.16;
        tz = -4.5;
        */

        if(i==0){
            valla31[i]->tx = -17.1;
            valla31[i]->tz = -4.5;
        }else if(i >= 1 && i <= 2){
            valla31[i]->tx = valla31[i-1]->tx + 3.5;
        }
        else if(i == 3){
            valla31[i]->tz = valla31[0]->tz + 9.36;
            valla31[i]->tx = valla31[0]->tx;
        }else if(i > 3){
            valla31[i]->tz = valla31[i-1]->tz;
            valla31[i]->tx = valla31[i-1]->tx + 3.5;
        }

        AddObject(valla31[i]);
    }

    TPrimitiva *valla32[6];
    for(int i = 0; i<6; i++){
        valla32[i] = new TPrimitiva(VALLA3_ID, VALLA3_ID);

        valla32[i]->ry = valla32[i]->ry + 90;

        valla32[i]->colores[0][0] = 0.5;
        valla32[i]->colores[0][1] = 0.2;
        valla32[i]->colores[0][2] = 0.2;

        /*
        tx = 20.16;
        tz = -4.5;
        */

        if(i == 0){
            valla32[i]->tx = -3.1;
            valla32[i]->tz = -18.52;
        }else if(i >= 1 && i <= 2){
            valla32[i]->tx = valla32[0]->tx;
            valla32[i]->tz = valla32[i-1]->tz + 3.5;
        }else if(i == 3){
            valla32[i]->tx = valla32[0]->tx + 9.36;
            valla32[i]->tz = valla32[0]->tz;
        }else if(i > 3){
            valla32[i]->tx = valla32[i-1]->tx;
            valla32[i]->tz = valla32[i-1]->tz + 3.5;
        }

        AddObject(valla32[i]);
    }

    TPrimitiva *valla33[6];
    for(int i = 0; i<6; i++){
        valla33[i] = new TPrimitiva(VALLA3_ID, VALLA3_ID);

        valla33[i]->ry = valla33[i]->ry + 90;

        valla33[i]->colores[0][0] = 0.5;
        valla33[i]->colores[0][1] = 0.2;
        valla33[i]->colores[0][2] = 0.2;

        /*
        tx = 20.16;
        tz = -4.5;
        */

        if(i == 0){
            valla33[i]->tx = -3.1;
            valla33[i]->tz = +18.52;
        }else if(i >= 1 && i <= 2){
            valla33[i]->tx = valla33[0]->tx;
            valla33[i]->tz = valla33[i-1]->tz - 3.5;
        }else if(i == 3){
            valla33[i]->tx = valla33[0]->tx + 9.36;
            valla33[i]->tz = valla33[0]->tz;
        }else if(i > 3){
            valla33[i]->tx = valla33[i-1]->tx;
            valla33[i]->tz = valla33[i-1]->tz - 3.5;
        }

        AddObject(valla33[i]);
    }

    TPrimitiva *farola0[6];
    for(int i = 0; i<6; i++){
        farola0[i] = new TPrimitiva(FAROLA_ID, FAROLA_ID);

        farola0[i]->colores[0][0] = 0;
        farola0[i]->colores[0][1] = 0.5;
        farola0[i]->colores[0][2] = 0.9;

        if(i >= 1 && i<= 2){
            farola0[i]->tx = farola0[i-1]->tx - 3.5;
        }else if(i == 3){
            farola0[i]->tz = farola0[0]->tz + 9.36;
            farola0[i]->tx = farola0[0]->tx;
        }else if(i > 3){
            farola0[i]->tx = farola0[i-1]->tx - 3.5;
            farola0[i]->tz = farola0[i-1]->tz;
        }

        AddObject(farola0[i]);
    }

    TPrimitiva *farola1[6];
    for(int i = 0; i<6; i++){
        farola1[i] = new TPrimitiva(FAROLA_ID, FAROLA_ID);

        farola1[i]->colores[0][0] = 0;
        farola1[i]->colores[0][1] = 0.5;
        farola1[i]->colores[0][2] = 0.9;

        /*tx = 21.91;
		    tz = -4.5;*/

        if(i == 0){
            farola1[i]->tx = -18.78;
        }else if(i >= 1 && i<= 2){
            farola1[i]->tx = farola1[i-1]->tx + 3.46;
        }else if(i == 3){
            farola1[i]->tz = farola1[0]->tz + 9.36;
            farola1[i]->tx = farola1[0]->tx;
        }else if(i > 3){
            farola1[i]->tx = farola1[i-1]->tx + 3.46;
            farola1[i]->tz = farola1[i-1]->tz;
        }

        AddObject(farola1[i]);
    }

    TPrimitiva *farola2[6];
    for(int i = 0; i<6; i++){
        farola2[i] = new TPrimitiva(FAROLA_ID, FAROLA_ID);

        farola2[i]->ry = farola2[i]->ry + 90;

        farola2[i]->colores[0][0] = 0;
        farola2[i]->colores[0][1] = 0.5;
        farola2[i]->colores[0][2] = 0.9;

        /*tx = 21.91;
		    tz = -4.5;*/

        if(i == 0){
            farola2[i]->tx = -3.1;
            farola2[i]->tz = -20.25;
        }else if(i >= 1 && i<= 2){
            farola2[i]->tx = farola2[i-1]->tx;
            farola2[i]->tz = farola2[i-1]->tz + 3.46;
        }else if(i == 3){
            farola2[i]->tx = farola2[0]->tx + 9.36;
            farola2[i]->tz = farola2[0]->tz;
        }else if(i > 3){
            farola2[i]->tz = farola2[i-1]->tz + 3.46;
            farola2[i]->tx = farola2[i-1]->tx;
        }

        AddObject(farola2[i]);
    }

    TPrimitiva *farola3[6];
    for(int i = 0; i<6; i++){
        farola3[i] = new TPrimitiva(FAROLA_ID, FAROLA_ID);

        farola3[i]->ry = farola3[i]->ry + 90;

        farola3[i]->colores[0][0] = 0;
        farola3[i]->colores[0][1] = 0.5;
        farola3[i]->colores[0][2] = 0.9;

        /*tx = 21.91;
		    tz = -4.5;*/

        if(i == 0){
            farola3[i]->tx = -3.1;
            farola3[i]->tz = 20.25;
        }else if(i >= 1 && i<= 2){
            farola3[i]->tx = farola3[i-1]->tx;
            farola3[i]->tz = farola3[i-1]->tz - 3.46;
        }else if(i == 3){
            farola3[i]->tx = farola3[0]->tx + 9.36;
            farola3[i]->tz = farola3[0]->tz;
        }else if(i > 3){
            farola3[i]->tz = farola3[i-1]->tz - 3.46;
            farola3[i]->tx = farola3[i-1]->tx;
        }

        AddObject(farola3[i]);
    }

    TPrimitiva *papeleras[4];
    for(int i = 0; i<4; i++){
        papeleras[i] = new TPrimitiva(PAPELERA_ID, PAPELERA_ID);

        papeleras[i]->colores[0][0] = 0.3;
        papeleras[i]->colores[0][1] = 0.3;
        papeleras[i]->colores[0][2] = 0.8;

        if(i == 1){
            papeleras[i]->tz = papeleras[i]->tz*-1;
            papeleras[i]->tx = papeleras[i]->tx*1;
            papeleras[i]->ry = papeleras[i-1]->ry + 90;
        }else if(i == 2){
            papeleras[i]->tx = - 9.75;
            papeleras[i]->ry = papeleras[0]->ry - 90;
        }else if(i == 3){
            papeleras[i]->tz = papeleras[i]->tz*-1;
            papeleras[i]->tx = papeleras[i]->tx - 22.75;
            papeleras[i]->ry = papeleras[0]->ry + 180;
        }

        AddObject(papeleras[i]);
    }
}

//************************************************************** Clase TGui

TGui::TGui()
{
    sel = 1;
    enable_panel2 = 1;
    light0_enabled = 1;
    light1_enabled = 1;
    light0_intensity = 0.8;
    light1_intensity = 0.8;
    memcpy(light0_position, light0_position_c, 4*sizeof(float));
    memcpy(light1_position, light1_position_c, 4*sizeof(float));
}

void controlCallback(int control)
{
    gui.ControlCallback(control);
}

void __fastcall TGui::Init(int main_window) {

    /****************************************************/
    /*        Código con el interfaz Gráfico GLUI       */
    /****************************************************/
    printf( "GLUI version: %3.2f\n", GLUI_Master.get_version() );

    window_id = main_window;

    /*** Crea a ventana lateral ***/
    glui = GLUI_Master.create_glui_subwindow( window_id, GLUI_SUBWINDOW_RIGHT );

    // Añade una separación
    new GLUI_StaticText( glui, "" );

    // Añade un panel con texto con el valor de la selección
    GLUI_Panel *panel0 = new GLUI_Panel(glui, "Seleccion");
    GLUI_RadioGroup *radioGroup = new GLUI_RadioGroup(panel0, &sel, SEL_ID, controlCallback);
    glui->add_radiobutton_to_group(radioGroup, "NINGUNO");


    glui->add_radiobutton_to_group(radioGroup, "COCHE 1");
    glui->add_radiobutton_to_group(radioGroup, "COCHE 2");


    // Añade una separación
    new GLUI_StaticText( glui, "" );

    obj_panel = new GLUI_Rollout(glui, "Propiedades", true );

    /***** Control para las propiedades de escena *****/

    new GLUI_Checkbox( obj_panel, "Modo Alambrico", &escena.wireframe, 1, controlCallback );
    glui->add_column_to_panel(obj_panel, true);
    new GLUI_Checkbox( obj_panel, "Culling", &escena.culling, 1, controlCallback );
    new GLUI_Checkbox( obj_panel, "Z Buffer", &escena.z_buffer, 1, controlCallback );

    /******** Añade controles para las luces ********/

    // Añade una separación
    new GLUI_StaticText( glui, "" );

    GLUI_Rollout *roll_lights = new GLUI_Rollout(glui, "Luces", true );

    GLUI_Panel *light0 = new GLUI_Panel( roll_lights, "Luz 1" );
    GLUI_Panel *light1 = new GLUI_Panel( roll_lights, "Luz 2" );

    new GLUI_Checkbox( light0, "Encendida", &light0_enabled, LIGHT0_ENABLED_ID, controlCallback );
    light0_spinner = new GLUI_Spinner( light0, "Intensidad:", &light0_intensity,
                            LIGHT0_INTENSITY_ID, controlCallback );
    light0_spinner->set_float_limits( 0.0, 1.0 );
    GLUI_Scrollbar *sb;
    sb = new GLUI_Scrollbar( light0, "X",GLUI_SCROLL_HORIZONTAL,
                            &escena.light0_position[0],LIGHT0_POSITION_ID,controlCallback);
    sb->set_float_limits(-100,100);
    sb = new GLUI_Scrollbar( light0, "Y",GLUI_SCROLL_HORIZONTAL,
                            &escena.light0_position[1],LIGHT0_POSITION_ID,controlCallback);
    sb->set_float_limits(-100,100);
    sb = new GLUI_Scrollbar( light0, "Z",GLUI_SCROLL_HORIZONTAL,
                            &escena.light0_position[2],LIGHT0_POSITION_ID,controlCallback);
    sb->set_float_limits(-100,100);

    new GLUI_Checkbox( light1, "Encendida", &light1_enabled, LIGHT1_ENABLED_ID, controlCallback );
    light1_spinner = new GLUI_Spinner( light1, "Intensidad:", &light1_intensity,
                            LIGHT1_INTENSITY_ID, controlCallback );
    light1_spinner->set_float_limits( 0.0, 1.0 );
    sb = new GLUI_Scrollbar( light1, "X",GLUI_SCROLL_HORIZONTAL,
                            &escena.light1_position[0],LIGHT1_POSITION_ID,controlCallback);
    sb->set_float_limits(-100,100);
    sb = new GLUI_Scrollbar( light1, "Y",GLUI_SCROLL_HORIZONTAL,
                            &escena.light1_position[1],LIGHT1_POSITION_ID,controlCallback);
    sb->set_float_limits(-100,100);
    sb = new GLUI_Scrollbar( light1, "Z",GLUI_SCROLL_HORIZONTAL,
                            &escena.light1_position[2],LIGHT1_POSITION_ID,controlCallback);
    sb->set_float_limits(-100,100);


    // Añade una separación
    new GLUI_StaticText( glui, "" );

    /***  Rollout de Opciones ***/
    GLUI_Rollout *options = new GLUI_Rollout(glui, "Opciones", false );
    new GLUI_Checkbox( options, "Dibujar Coche", &escena.show_car );
    new GLUI_Checkbox( options, "Dibujar Ruedas", &escena.show_wheels );
    new GLUI_Checkbox( options, "Dibujar Carretera", &escena.show_road );


    /*** Disable/Enable botones ***/
    // Añade una separación
    new GLUI_StaticText( glui, "" );
    new GLUI_Checkbox( glui, "Permitir Movimiento", &enable_panel2 );
    // Añade una separación
    new GLUI_StaticText( glui, "" );
    new GLUI_Button( glui, "Resetear Posicion", RESET_ID, controlCallback );

    // Añade una separación
    new GLUI_StaticText( glui, "" );

    new GLUI_Separator( glui );

     // Añade una separación
    new GLUI_StaticText( glui, "" );

    new GLUI_StaticText( glui, "  Autor:" );
    new GLUI_StaticText( glui, "  2012-2022 (C) Juan Antonio Puchol  " );

    // Añade una separación
    new GLUI_StaticText( glui, "" );

    new GLUI_Separator( glui );

    // Añade una separación
    new GLUI_StaticText( glui, "" );

    /****** A 'quit' button *****/
    new GLUI_Button( glui, "Salir", 0,(GLUI_Update_CB)exit );

    // Crea la subventana inferior
    glui2 = GLUI_Master.create_glui_subwindow( window_id, GLUI_SUBWINDOW_BOTTOM );

    /**** Link windows to GLUI, and register idle callback ******/
    glui->set_main_gfx_window( window_id );
    glui2->set_main_gfx_window( window_id );

    view_rot = new GLUI_Rotation(glui2, "Rotacion Escena", escena.view_rotate );
    view_rot->set_spin( 1.0 );
    new GLUI_Column( glui2, false );
    GLUI_Translation *trans_xy = new GLUI_Translation(glui2, "Traslacion Escena XY", GLUI_TRANSLATION_XY, escena.view_position );
    trans_xy->set_speed( .005 );
    new GLUI_Column( glui2, false );
    GLUI_Translation *trans_x =  new GLUI_Translation(glui2, "Traslacion Escena X", GLUI_TRANSLATION_X, escena.view_position );
    trans_x->set_speed( .005 );
    new GLUI_Column( glui2, false );
    GLUI_Translation *trans_y = new GLUI_Translation( glui2, "Traslacion Escena Y", GLUI_TRANSLATION_Y, &escena.view_position[1] );
    trans_y->set_speed( .005 );
    new GLUI_Column( glui2, false );
    GLUI_Translation *trans_z = new GLUI_Translation( glui2, "Traslacion Escena Z", GLUI_TRANSLATION_Z, &escena.scale );
    trans_z->set_speed( .005 );

}

/**************************************** TGui::ControlCallback() *******************/

void __fastcall TGui::ControlCallback( int control )
{
    switch (control) {
        case LIGHT0_ENABLED_ID: {
            if ( light0_enabled )
                light0_spinner->enable();
            else
                light0_spinner->disable();
            break;
        }
        case LIGHT1_ENABLED_ID: {
            if ( light1_enabled )
                light1_spinner->enable();
            else
                light1_spinner->disable();
            break;
        }
        case LIGHT0_INTENSITY_ID: {

            float v[] = {
                escena.light0_diffuse[0],  escena.light0_diffuse[1],
                escena.light0_diffuse[2],  escena.light0_diffuse[3] };

            v[0] *= light0_intensity;
            v[1] *= light0_intensity;
            v[2] *= light0_intensity;
            break;
        }
        case LIGHT1_INTENSITY_ID: {

            float v[] = {
                escena.light1_diffuse[0],  escena.light1_diffuse[1],
                escena.light1_diffuse[2],  escena.light1_diffuse[3] };

            v[0] *= light1_intensity;
            v[1] *= light1_intensity;
            v[2] *= light1_intensity;
            break;
        }
        case ENABLE_ID: {
            glui2->enable();
            break;
        }
        case DISABLE_ID: {
            glui2->disable();
            break;
        }
        case RESET_ID: {
            memcpy(escena.view_position,view_position_c,3*sizeof(float));
            view_rot->reset();
            escena.scale = 100.0;
            break;
        }
        case SEL_ID: {
            escena.seleccion = sel;
            //GLUI_Master.SetFocus(true);
            glutSetWindow( glui->get_glut_window_id() );
            break;
        }
  } // switch
}

/***************************************** TGui::Idle() ***********/

void __fastcall TGui::Idle( void )
{
  /* According to the GLUT specification, the current window is
     undefined during an idle callback.  So we need to explicitly change
     it if necessary */
  if ( glutGetWindow() != window_id )
    glutSetWindow(window_id);

  /*  GLUI_Master.sync_live_all();  -- not needed - nothing to sync in this
                                       application  */
    if (enable_panel2)

        glui2->enable();
    else
        glui2->disable();

  glutPostRedisplay();
}

/**************************************** TGui::reshape() *************/

void __fastcall TGui::Reshape( int xx, int yy )
{
    int x, y, ancho, alto;
    GLUI_Master.get_viewport_area( &x, &y, &ancho, &alto );
    glViewport( x, y, ancho, alto );

    // !!!!! ATENCIÓN: comprobar que alto no sea 0, sino división por 0 !!!!!!
    escena.xy_aspect = (float)ancho / (float)alto;
    escena.projectionMatrix = glm::perspective(45.0f, escena.xy_aspect, 0.1f, 1000.0f);
    glUniformMatrix4fv(escena.uProjectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(escena.projectionMatrix));

    //std::cout << "xy aspect: " << escena.xy_aspect << std::endl;

    glutPostRedisplay();
}

/***************************************** gui::motion() **********/

void __fastcall TGui::Motion(int x, int y )
{
    glutPostRedisplay();
}

/***************************************** gui::Mouse() **********/

void __fastcall TGui::Mouse(int button, int button_state, int x, int y )
{
    escena.Pick3D(x, y);
}

