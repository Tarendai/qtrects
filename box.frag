uniform sampler2D tex;
uniform float time;
uniform float useTexture;

void main()
{
	vec4 color = gl_Color;
	if(useTexture == 1){
		color = texture2D(tex,gl_TexCoord[0].st);
	}
	if(time < 30.0){
		color.a = time/30.0;
	} else {
		color.a += sin(time/32.0)/6.0;
	}
	gl_FragColor = color;
}
