#ifndef ARMA_H_
#define ARMA_H_

struct ar15;

struct ar15* nuevaArma();

void create(struct ar15*);
void destroy(struct ar15*);
void shootOne(struct ar15*);
void shootSemi(struct ar15*);
void shootAuto(struct ar15*);

#endif