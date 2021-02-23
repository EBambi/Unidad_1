#ifndef JUGADOR_H_
#define JUGADOR_H_

struct jugador;
struct ar15;

struct jugador* jugadorNuevo();
void createJ(struct jugador*, const char*);
void destroyJ(struct jugador*);
void pikUpA(struct jugador*, struct ar15*);
void shootOneJ(struct jugador*);
void shootSemiJ(struct jugador*);
void shootAutoJ(struct jugador*);
void dropA(struct jugador*);

#endif