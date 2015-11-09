struct FILE* fpPPM;
int y;
float pi=3.141592;
int iH=200;
print_Collumn(iR,iG,iB)
	int iR;
	int iG;
	int iB;
{	extern int fprintf(struct FILE*,char*,...);
	char* szFmt="%d %d %d\n";
	fprintf( fpPPM,szFmt,iR,iG,iB );
	
	}
put_Header()
{	char* szHead="P3\n#\n200 200\n255\n";
	fpPPM=fopen( "out.ppm","w" );
	fwrite( szHead,1,strlen(szHead),fpPPM );
	
	}
print_Done()
{	fclose( fpPPM );
	
	}
put_Row(iW)
	int iW;
{	int x;
	for(x=0;x<iW;x++)
	{	float bx=x;
		float by=y;
		float v;
		float r;
		float g;
		float b;
		v = sin(-bx/32.);
		v += cos(-by/32.);
		v += sin((-bx+-by)/32.);
		v += sin((sqrt(((bx)*(bx))+((by)*(by))+1.))/128.);
		r = sin(v*pi)*127.5+127.5;
		g = (cos(v*pi)*127.5+127.5)*.6;
		print_Collumn( r,g,b*.0 );
		
		}
		
	}
main(_iArgCount,_rgszArgStrings,_rgszEnvPointer)
	int _iArgCount;
	char** _rgszArgStrings;
	char** _rgszEnvPointer;
{	put_Header(  );
	for(y=0;y<iH;y++)
	{	put_Row( 200 );
		
		}
	print_Done(  );
	return(0);
	
	}
