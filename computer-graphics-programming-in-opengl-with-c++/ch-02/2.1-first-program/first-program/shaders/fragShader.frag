//uniform sampler2D qt_Texture0;
//varying vec4 qt_TexCoord0;

//void main(void)
//{
//    gl_FragColor = texture2D(qt_Texture0, qt_TexCoord0.st);
//}

out vec4 color;
void main(void)
{
    if(gl_FragCoord.x < 200)
    {
        color = vec4(1.0,0.0,0.0,1.0);
    }
    else
    {
        color = vec4(0.0,0.0,1.0,1.0);
    }
}
