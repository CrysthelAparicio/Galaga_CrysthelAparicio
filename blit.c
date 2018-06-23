#include <curses.h>
#include "defs.h"
#include "util.h"

extern int x_ofs;
extern int y_ofs;
extern int term_x;
extern int term_y;
extern WINDOW *term; // La terminal

// Explosion Sangrosa
//http://es.tldp.org/Allegro-es/web/online/alleg013.html#blit de aqui saque la idea de un blit....
/* Todas las funciones de explosión se deben llamar con las coordenadas
del punto central como parámetros */

void blit_explosion_1(int x, int y)
{
/*
 .
#@#
 "
*/
	SET_COLOR(COL_DARKYELLOW);
	if (es_y_rango(y-1))
	{
		mvwaddch(term,y-1,x,(chtype)'.');
	}
	if (es_y_rango(y))
	{
		if (es_x_rango(x-1)) mvwaddch(term,y,x-1,(chtype)'#');
		SET_COLOR(COL_DARKRED);
		mvwaddch(term,y,x,(chtype)'@');
		SET_COLOR(COL_DARKYELLOW);
		if (es_x_rango(x+1)) mvwaddch(term,y,x+1,(chtype)'#');
	}
	if (es_y_rango(y+1))
	{
		mvwaddch(term,y+1,x,(chtype)'"');
	}
	SET_COLOR(COL_BKG);
}

void limpiar_explosion_1(int x, int y)
{
	SET_COLOR(COL_BKG);
	if (es_y_rango(y-1))
	{
		mvwaddch(term,y-1,x,(chtype)' ');
	}
	if (es_y_rango(y))
	{
		if (es_x_rango(x-1)) mvwaddch(term,y,x-1,(chtype)' ');
		mvwaddch(term,y,x,(chtype)' ');
		if (es_x_rango(x+1)) mvwaddch(term,y,x+1,(chtype)' ');
	}
	if (es_y_rango(y+1))
	{
		mvwaddch(term,y+1,x,(chtype)' ');
	}
}

void blit_explosion_2(int x, int y)
{
/*
 @ 
@#@
 @ 
*/
	SET_COLOR(COL_DARKRED);
	if (es_y_rango(y-1))
	{
		mvwaddch(term,y-1,x,(chtype)'@');
	}
	if (es_y_rango(y))
	{
		if (es_x_rango(x-1)) mvwaddch(term,y,x-1,(chtype)'#');
		SET_COLOR(COL_RED);
		mvwaddch(term,y,x,(chtype)'@');
		SET_COLOR(COL_DARKRED);
		if (es_x_rango(x+1)) mvwaddch(term,y,x+1,(chtype)'#');
	}
	if (es_y_rango(y+1))
	{
		mvwaddch(term,y+1,x,(chtype)'@');
	}
	SET_COLOR(COL_BKG);
}

void limpiar_explosion_2(int x, int y)
{
	limpiar_explosion_1(x,y);
}

void blit_explosion_3(int x, int y)
{
/*
  .
 #@#
#@#@#
 #@#
  "
*/

	SET_COLOR(COL_DARKRED);
	if (es_y_rango(y-2))
	{
		mvwaddch(term,y-2,x,(chtype)'.');
	}
	if (es_y_rango(y-1))
	{
		if (es_x_rango(x-1)) mvwaddch(term,y-1,x-1,(chtype)'#');
		SET_COLOR(COL_RED);
		mvwaddch(term,y-1,x,(chtype)'@');
		SET_COLOR(COL_DARKRED);
		if (es_x_rango(x+1)) mvwaddch(term,y-1,x+1,(chtype)'#');
	}
	if (es_y_rango(y))
	{
		if (es_x_rango(x-2)) mvwaddch(term,y,x-2,(chtype)'#');
		SET_COLOR(COL_RED);
		if (es_x_rango(x-1)) mvwaddch(term,y,x-1,(chtype)'@');
		SET_COLOR(COL_YELLOW);
		mvwaddch(term,y,x,(chtype)'#');
		SET_COLOR(COL_RED);
		if (es_x_rango(x+1)) mvwaddch(term,y,x+1,(chtype)'@');
		SET_COLOR(COL_DARKRED);
		if (es_x_rango(x+2)) mvwaddch(term,y,x+2,(chtype)'#');
	}
	if (es_y_rango(y+1))
	{
		if (es_x_rango(x-1)) mvwaddch(term,y+1,x-1,(chtype)'#');
		SET_COLOR(COL_RED);
		mvwaddch(term,y+1,x,(chtype)'@');
		SET_COLOR(COL_DARKRED);
		if (es_x_rango(x+1)) mvwaddch(term,y+1,x+1,(chtype)'#');
	}
	if (es_y_rango(y+2))
	{
		mvwaddch(term,y+2,x,(chtype)'"');
	}
	SET_COLOR(COL_BKG);
}

void limpiar_explosion_3(int x, int y)
{
	SET_COLOR(COL_BKG);
	if (es_y_rango(y-2))
	{
		mvwaddch(term,y-2,x,(chtype)' ');
	}
	if (es_y_rango(y-1))
	{
		if (es_x_rango(x-1)) mvwaddch(term,y-1,x-1,(chtype)' ');
		mvwaddch(term,y-1,x,(chtype)' ');
		if (es_x_rango(x+1)) mvwaddch(term,y-1,x+1,(chtype)' ');
	}
	if (es_y_rango(y))
	{
		if (es_x_rango(x-2)) mvwaddch(term,y,x-2,(chtype)' ');
		if (es_x_rango(x-1)) mvwaddch(term,y,x-1,(chtype)' ');
		mvwaddch(term,y,x,(chtype)' ');
		if (es_x_rango(x+1)) mvwaddch(term,y,x+1,(chtype)' ');
		if (es_x_rango(x+2)) mvwaddch(term,y,x+2,(chtype)' ');
	}
	if (es_y_rango(y+1))
	{
		if (es_x_rango(x-1)) mvwaddch(term,y+1,x-1,(chtype)' ');
		mvwaddch(term,y+1,x,(chtype)' ');
		if (es_x_rango(x+1)) mvwaddch(term,y+1,x+1,(chtype)' ');
	}
	if (es_y_rango(y+2))
	{
		mvwaddch(term,y+2,x,(chtype)' ');
	}
}

void blit_explosion_4(int x, int y)
{
/*
   .
  @#@
 @#@#@
@#@#@#@
 @#@#@
  @#@
   "
*/
	SET_COLOR(COL_DARKYELLOW);
	if (es_y_rango(y-3))
	{
		mvwaddch(term,y-3,x,(chtype)'.');
	}
	if (es_y_rango(y-2))
	{
		if (es_x_rango(x-1)) mvwaddch(term,y-2,x-1,(chtype)'@');
		SET_COLOR(COL_DARKRED);
		mvwaddch(term,y-2,x,(chtype)'#');
		SET_COLOR(COL_DARKYELLOW);
		if (es_x_rango(x+1)) mvwaddch(term,y-2,x+1,(chtype)'@');
	}
	if (es_y_rango(y-1))
	{
		if (es_x_rango(x-2)) mvwaddch(term,y-1,x-2,(chtype)'@');
		SET_COLOR(COL_DARKRED);
		if (es_x_rango(x-1)) mvwaddch(term,y-1,x-1,(chtype)'#');
		SET_COLOR(COL_RED);
		mvwaddch(term,y-1,x,(chtype)'@');
		SET_COLOR(COL_DARKRED);
		if (es_x_rango(x+1)) mvwaddch(term,y-1,x+1,(chtype)'#');
		SET_COLOR(COL_DARKYELLOW);
		if (es_x_rango(x+2)) mvwaddch(term,y-1,x+2,(chtype)'@');
	}
	if (es_y_rango(y))
	{
		if (es_x_rango(x-3)) mvwaddch(term,y,x-3,(chtype)'@');
		SET_COLOR(COL_DARKRED);
		if (es_x_rango(x-2)) mvwaddch(term,y,x-2,(chtype)'#');
		SET_COLOR(COL_RED);
		if (es_x_rango(x-1)) mvwaddch(term,y,x-1,(chtype)'@');
		SET_COLOR(COL_YELLOW);
		mvwaddch(term,y,x,(chtype)'#');
		SET_COLOR(COL_RED);
		if (es_x_rango(x+1)) mvwaddch(term,y,x+1,(chtype)'@');
		SET_COLOR(COL_DARKRED);
		if (es_x_rango(x+2)) mvwaddch(term,y,x+2,(chtype)'#');
		SET_COLOR(COL_DARKYELLOW);
		if (es_x_rango(x+3)) mvwaddch(term,y,x+3,(chtype)'@');
	}
	if (es_y_rango(y+1))
	{
		if (es_x_rango(x-2)) mvwaddch(term,y+1,x-2,(chtype)'@');
		SET_COLOR(COL_DARKRED);
		if (es_x_rango(x-1)) mvwaddch(term,y+1,x-1,(chtype)'#');
		SET_COLOR(COL_RED);
		mvwaddch(term,y+1,x,(chtype)'@');
		SET_COLOR(COL_DARKRED);
		if (es_x_rango(x+1)) mvwaddch(term,y+1,x+1,(chtype)'#');
		SET_COLOR(COL_DARKYELLOW);
		if (es_x_rango(x+2)) mvwaddch(term,y+1,x+2,(chtype)'@');
	}
	if (es_y_rango(y+2))
	{
		if (es_x_rango(x-1)) mvwaddch(term,y+2,x-1,(chtype)'@');
		SET_COLOR(COL_DARKRED);
		mvwaddch(term,y+2,x,(chtype)'#');
		SET_COLOR(COL_DARKYELLOW);
		if (es_x_rango(x+1)) mvwaddch(term,y+2,x+1,(chtype)'@');
	}
	if (es_y_rango(y+3))
	{
		mvwaddch(term,y+3,x,(chtype)'"');
	}
	SET_COLOR(COL_BKG);
}

void limpiar_explosion_4(int x, int y)
{
	SET_COLOR(COL_BKG);
	if (es_y_rango(y-3))
	{
		mvwaddch(term,y-3,x,(chtype)' ');
	}
	if (es_y_rango(y-2))
	{
		if (es_x_rango(x-1)) mvwaddch(term,y-2,x-1,(chtype)' ');
		mvwaddch(term,y-2,x,(chtype)' ');
		if (es_x_rango(x+1)) mvwaddch(term,y-2,x+1,(chtype)' ');
	}
	if (es_y_rango(y-1))
	{
		if (es_x_rango(x-2)) mvwaddch(term,y-1,x-2,(chtype)' ');
		if (es_x_rango(x-1)) mvwaddch(term,y-1,x-1,(chtype)' ');
		mvwaddch(term,y-1,x,(chtype)' ');
		if (es_x_rango(x+1)) mvwaddch(term,y-1,x+1,(chtype)' ');
		if (es_x_rango(x+2)) mvwaddch(term,y-1,x+2,(chtype)' ');
	}
	if (es_y_rango(y))
	{
		if (es_x_rango(x-3)) mvwaddch(term,y,x-3,(chtype)' ');
		if (es_x_rango(x-2)) mvwaddch(term,y,x-2,(chtype)' ');
		if (es_x_rango(x-1)) mvwaddch(term,y,x-1,(chtype)' ');
		mvwaddch(term,y,x,(chtype)' ');
		if (es_x_rango(x+1)) mvwaddch(term,y,x+1,(chtype)' ');
		if (es_x_rango(x+2)) mvwaddch(term,y,x+2,(chtype)' ');
		if (es_x_rango(x+3)) mvwaddch(term,y,x+3,(chtype)' ');
	}
	if (es_y_rango(y+1))
	{
		if (es_x_rango(x-2)) mvwaddch(term,y+1,x-2,(chtype)' ');
		if (es_x_rango(x-1)) mvwaddch(term,y+1,x-1,(chtype)' ');
		mvwaddch(term,y+1,x,(chtype)' ');
		if (es_x_rango(x+1)) mvwaddch(term,y+1,x+1,(chtype)' ');
		if (es_x_rango(x+2)) mvwaddch(term,y+1,x+2,(chtype)' ');
	}
	if (es_y_rango(y+2))
	{
		if (es_x_rango(x-1)) mvwaddch(term,y+2,x-1,(chtype)' ');
		mvwaddch(term,y+2,x,(chtype)' ');
		if (es_x_rango(x+1)) mvwaddch(term,y+2,x+1,(chtype)' ');
	}
	if (es_y_rango(y+3))
	{
		mvwaddch(term,y+3,x,(chtype)' ');
	}
}

void blit_explosion(int x, int y, int dim)
{
	switch (dim)
	{
	case 1:
		blit_explosion_1(x,y);
		break;
	case 2:
		blit_explosion_2(x,y);
		break;
	case 3:
		blit_explosion_3(x,y);
		break;
	case 4:
		blit_explosion_4(x,y);
		break;
	}
}

void limpiar_explosion(int x, int y, int dim)
{
	switch (dim)
	{
	case 1:
		limpiar_explosion_1(x,y);
		break;
	case 2:
		limpiar_explosion_2(x,y);
		break;
	case 3:
		limpiar_explosion_3(x,y);
		break;
	case 4:
		limpiar_explosion_4(x,y);
		break;
	}
}

// Final de la explosion sangrosa xD

void blit_grande_nave(int x, int y)
{
/*
Nave Grande:

|-v-|
| o |
 \_/
*/
	if (es_y_rango(y))
	{
		SET_COLOR(COL_GREEN);
		mvwprintw(term,y,x,"|-");
		SET_COLOR(COL_BLUE);
		wprintw(term,"v");
		SET_COLOR(COL_GREEN);
		wprintw(term,"-|");
	}
	if (es_y_rango(y+1))
	{
		SET_COLOR(COL_GREEN);
		mvwprintw(term,y+1,x,"| ");
		SET_COLOR(COL_CYAN);
		wprintw(term,"o");
		SET_COLOR(COL_GREEN);
		wprintw(term," |");
	}
	if (es_y_rango(y+2))
	{
		SET_COLOR(COL_GREEN);
		mvwprintw(term,y+2,x+1,"\\_/");
	}
	SET_COLOR(COL_BKG);
}

void limpiar_grande_nave(int x, int y)
{
	SET_COLOR(COL_BKG);
	if (es_y_rango(y)) mvwprintw(term,y,x,      "     ");
	if (es_y_rango(y+1)) mvwprintw(term,y+1,x,  "     ");
	if (es_y_rango(y+2)) mvwprintw(term,y+2,x+1, "   ");
}

void blit_peque_nave(int x,int y)
{
/*
Nave Pequeña:

W_W
 "
*/
	if (es_y_rango(y))
	{
		SET_COLOR(COL_BLUE);
		mvwprintw(term,y,x,"W W");
		SET_COLOR(COL_WHITE);
		mvwaddch(term,y,x+1,(chtype)'_');
	}
	if (es_y_rango(y+1))
	{
		SET_COLOR(COL_RED);
		mvwprintw(term,y+1,x+1,"\"");
	}
	SET_COLOR(COL_BKG);
}

void limpiar_peque_nave(int x, int y)
{
	SET_COLOR(COL_BKG);
	if (es_y_rango(y)) mvwprintw(term,y,x,"   ");
	if (es_y_rango(y+1)) mvwprintw(term,y+1,x+1," ");
}

void blit_bola_nave(int x,int y)
{
/*
/^\
\_/
*/
	SET_COLOR(COL_DARKMAGENTA);
	if (es_y_rango(y)) mvwprintw(term,y,x,"/^\\");
	if (es_y_rango(y+1)) mvwprintw(term,y+1,x,"\\_/");
	SET_COLOR(COL_BKG);
}

void limpiar_bola_nave(int x,int y)
{
	SET_COLOR(COL_BKG);
	if (es_y_rango(y)) mvwprintw(term,y,x,"   ");
	if (es_y_rango(y+1)) mvwprintw(term,y+1,x,"   ");
}

void blit_limo_nave(int x,int y)
{
/*
/~T~\
\/|\/
*/
	if (es_y_rango(y))
	{
		SET_COLOR(COL_BLUE);
		mvwprintw(term,y,x,"/");
		SET_COLOR(COL_RED);
		wprintw(term,"~T~");
		SET_COLOR(COL_BLUE);
		wprintw(term,"\\");
	}
	if (es_y_rango(y+1))
	{
		SET_COLOR(COL_BLUE);
		mvwprintw(term,y+1,x,"\\/");
		SET_COLOR(COL_RED);
		wprintw(term,"|");
		SET_COLOR(COL_BLUE);
		wprintw(term,"\\/");
	}
	SET_COLOR(COL_BKG);
}

void limpiar_limo_nave(int x,int y)
{
	SET_COLOR(COL_BKG);
	if (es_y_rango(y)) mvwprintw(term,y,x,"     ");
	if (es_y_rango(y+1)) mvwprintw(term,y+1,x,"     ");
}

void blit_mini_nave(int x,int y)
{
/*
o
*/
	SET_COLOR(COL_GREEN);
	if (es_y_rango(y)) mvwprintw(term,y,x,"o");
	SET_COLOR(COL_BKG);
}

void limpiar_mini_nave(int x,int y)
{
	SET_COLOR(COL_BKG);
	if (es_y_rango(y)) mvwprintw(term,y,x," ");
}

void blit_fuego(int x,int y)
{
	if (es_y_rango(y))
	{
		SET_COLOR(COL_RED);
		mvwaddch(term,y,x,(chtype)'!');
		SET_COLOR(COL_BKG);
	}
}

void limpiar_fuego(int x, int y)
{
	if (es_y_rango(y))
	{
		SET_COLOR(COL_BKG);
		mvwaddch(term,y,x,(chtype)' ');
	}
}

void blit_nave(int x,int y)
{
/* Esta es la nave de los vengadores, va cambiando en cada nivel:
  /^\
 | _ |
< /_\ >
 ^^^^^
*/

	if (es_y_rango(y))
	{
		SET_COLOR(COL_GRAY);
		mvwprintw(term,y,x+2,  "/^\\");
	}
	
	if (es_y_rango(y+1))
	{
		SET_COLOR(COL_GRAY);
		mvwprintw(term,y+1,x+1,"| ");
		SET_COLOR(COL_DARKCYAN);
		wprintw(term,"_");
		SET_COLOR(COL_GRAY);
		wprintw(term," |");
	}

	if (es_y_rango(y+2))
	{
		SET_COLOR(COL_GRAY);
		mvwprintw(term,y+2,x,"< ");
		SET_COLOR(COL_DARKCYAN);
		wprintw(term,"/_\\");
		SET_COLOR(COL_GRAY);
		wprintw(term," >");
	}

	if (es_y_rango(y+3))
	{
		SET_COLOR(COL_YELLOW);
		mvwprintw(term,y+3,x+1,"^");
		SET_COLOR(COL_RED);
		wprintw(term,"^^^");
		SET_COLOR(COL_YELLOW);
		wprintw(term,"^");
	}

	SET_COLOR(COL_BKG);
}

void limpiar_nave(int x,int y)
{
	SET_COLOR(COL_BKG);
	if (es_y_rango(y)) mvwprintw(term,y,x+2,    "   ");
	if (es_y_rango(y+1)) mvwprintw(term,y+1,x+1, "     ");
	if (es_y_rango(y+2)) mvwprintw(term,y+2,x,  "       ");
	if (es_y_rango(y+3)) mvwprintw(term,y+3,x+1, "     ");
}

void blit_escudo(int x,int y,int intensity)
{
/* El escudo del Cap, no lo pude hacer circular:

/~~~^~~~\

*/
	int col1=COL_DARKGREEN,col2=COL_DARKGREEN,col3=COL_DARKGREEN;
	switch (intensity)
	{
	case 3:
		col2=COL_GREEN;
		col3=COL_CYAN;
		break;
	case 2:
		col3=COL_GREEN;
		break;
	}

	if (es_x_rango(x))
	{
		SET_COLOR(col1);
		mvwprintw(term,y,x,"/");
	}
	SET_COLOR(col2);
	mvwprintw(term,y,x+1,"~~");
	SET_COLOR(col3);
	wprintw(term,"~^~");
	SET_COLOR(col2);
	wprintw(term,"~~");
	if (es_x_rango(x+8))
	{
		SET_COLOR(col1);
		wprintw(term,"\\");
	}
	SET_COLOR(COL_BKG);
}

void blit_escudo_carga(int x, int y, int length)
{
	int i;
	for (i=0;i<length;i++)
	{
		switch(i)
		{
		case 0:
			SET_COLOR(COL_DARKYELLOW);
			break;
		case 5:
			SET_COLOR(COL_DARKRED);
			break;
		case 10:
			SET_COLOR(COL_RED);
			break;
		case 15:
			SET_COLOR(COL_YELLOW);
			break;
		}
		mvprintw(y,i+x,"-");
	}
	SET_COLOR(COL_BKG);
}

void limpiar_escudo(int x,int y)
{
	SET_COLOR(COL_BKG);
	if (es_x_rango(x))
	{
		mvwprintw(term,y,x," ");
	}
	mvwprintw(term,y,x+1,"       ");
	if (es_x_rango(x+8))
	{
		wprintw(term," ");
	}
}

void limpiar_escudo_carga(int x, int y)
{
	SET_COLOR(COL_BKG);
	mvwprintw(term,y,x,"                    ");
}

void blit_puntaje(int x, int y, int puntaje)
{
	SET_COLOR(COL_WHITE);
	mvwprintw(term,y,x,"%d",puntaje);
	SET_COLOR(COL_BKG);
}

void blit_thanos(int x,int y,unsigned int extra)
{
/*
GUANTELETE
 /^~~^~~^\
( o o o o )
 \ ~\~/~ /
  > O O <
 (_/\_/\_)
*/
	int eye_col = (extra & 0xFF);
	unsigned char gemas    = ((extra & 0xFF00) >> 8);
	if (es_y_rango(y))
	{
		SET_COLOR(COL_BLUE);
		mvwprintw(term,y,x+1,"/");
		SET_COLOR(COL_RED);
		wprintw(term,"^");
		SET_COLOR(COL_BLUE);
		wprintw(term,"~~");
		SET_COLOR(COL_RED);
		wprintw(term,"^");
		SET_COLOR(COL_BLUE);
		wprintw(term,"~~");
		SET_COLOR(COL_RED);
		wprintw(term,"^");
		SET_COLOR(COL_BLUE);
		wprintw(term,"\\");
	}
	if (es_y_rango(y+1))
	{
		int cnt=0;
		SET_COLOR(COL_BLUE);
		mvwprintw(term,y+1,x,"(");
		SET_COLOR(COL_GREEN);
		while (cnt<4)
		{
			if (gemas & (1<<(cnt++)))
				wprintw(term," o");
			else
				wprintw(term,"  ");
		}
		SET_COLOR(COL_BLUE);
		wprintw(term," )");
	}
	if (es_y_rango(y+2))
	{
		SET_COLOR(COL_BLUE);
		mvwprintw(term,y+2,x+1,"\\ ~");
		SET_COLOR(COL_DARKCYAN);
		wprintw(term,"\\");
		SET_COLOR(COL_BLUE);
		wprintw(term,"~");
		SET_COLOR(COL_DARKCYAN);
		wprintw(term,"/");
		SET_COLOR(COL_BLUE);
		wprintw(term,"~ /");
	}
	if (es_y_rango(y+3))
	{
		SET_COLOR(COL_BLUE);
		mvwprintw(term,y+3,x+2,"> ");
		SET_COLOR(eye_col);
		wprintw(term,"O O");
		SET_COLOR(COL_BLUE);
		wprintw(term," <");
	}
	if (es_y_rango(y+4))
	{
		SET_COLOR(COL_BLUE);
		mvwprintw(term,y+4,x+1,"(_");
		SET_COLOR(COL_DARKRED);
		wprintw(term,"/\\_/\\");
		SET_COLOR(COL_BLUE);
		wprintw(term,"_)");
	}
	SET_COLOR(COL_BKG);
}

void limpiar_thanos(int x,int y)
{
	SET_COLOR(COL_BKG);
	if (es_y_rango(y))
	{
		mvwprintw(term,y,x+1,"         ");
	}
	if (es_y_rango(y+1))
	{
		mvwprintw(term,y+1,x,"           ");
	}
	if (es_y_rango(y+2))
	{
		mvwprintw(term,y+2,x+1,"         ");
	}
	if (es_y_rango(y+3))
	{
		mvwprintw(term,y+3,x+2,"       ");
	}
	if (es_y_rango(y+4))
	{
		mvwprintw(term,y+4,x+1,"         ");
	}
}

void blit_bordes(int color)
{
	int i;
	SET_COLOR(color);
	if (y_ofs-1 >= 0)
	{
		for (i=x_ofs;i<80+x_ofs;i++)
			mvwaddch(term,y_ofs-1,i,(chtype)'-');
	}
	if (y_ofs+25 < term_y)
	{
		for (i=x_ofs;i<80+x_ofs;i++)
			mvwaddch(term,y_ofs+25,i,(chtype)'-');
	}

	if (x_ofs-1 >= 0)
	{
		for (i=y_ofs;i<25+y_ofs;i++)
			mvwaddch(term,i,x_ofs-1,(chtype)'|');
	}
	if (x_ofs+80 < term_x)
	{
		for (i=y_ofs;i<25+y_ofs;i++)
			mvwaddch(term,i,x_ofs+80,(chtype)'|');
	}

	if ((x_ofs-1 >= 0) && (y_ofs-1 >= 0))
		mvwaddch(term,y_ofs-1,x_ofs-1,(chtype)'+');
	if ((x_ofs-1 >= 0) && (y_ofs+25 < term_y))
		mvwaddch(term,y_ofs+25,x_ofs-1,(chtype)'+');
	if ((x_ofs+80 < term_x) && (y_ofs-1 >= 0))
		mvwaddch(term,y_ofs-1,x_ofs+80,(chtype)'+');
	if ((x_ofs+80 < term_x) && (y_ofs+25 < term_y))
		mvwaddch(term,y_ofs+25,x_ofs+80,(chtype)'+');

	SET_COLOR(COL_BKG);
}