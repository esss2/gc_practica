
precision mediump float;	// Precisi�n media, en algunas gr�ficas no se soporta (depende de la versi�n de GLSL), en ese caso comentar o quitar esta l�nea

varying vec4 v_Color;		// in: color del vertex shader

void main()
{
    		gl_FragColor = v_Color;
}
