#include <iostream>
#include <cmath>

int Triangle(int index)
{
   return (index*(index+1))/2;
}

int Square(int index)
{
   return index*index;
}

int Penta(int index)
{
   return (index*(3*index-1))/2;
}

int Hexa(int index)
{
   return index*(2*index-1);
}

int Hepta(int index)
{
   return (index*(5*index-3))/2;
}

int Octa(int index)
{
   return index*(3*index-2);
}

// New elements are added into the beginning of the queue
class Cycle{
   public:
      int triangle;
      int square;
      int penta;
      int hexa;
      int hepta;
      int octa;
      int amount;
      int first;
      int last;
      Cycle()
      {
         triangle = 0;
         square = 0;
         penta = 0;
         hexa = 0;
         hepta = 0; 
         octa = 0;
         first = 0;
         last = 0;
      }
      Cycle(int addition)
      {
         triangle = 0;
         square = 0;
         penta = 0;
         hexa = 0;
         hepta = 0;
         octa = addition;
         first = addition/100;
         last = addition%100;
      }
      // Types: 0 (triangle), 1 (square), 2 (penta), 3 (hexa), 4 (hepta)
      Cycle(Cycle previous, int addition, int type)
      {
         triangle = previous.triangle;
         square = previous.square;
         penta = previous.penta;
         hexa = previous.hexa;
         hepta = previous.hepta;
         octa = previous.octa;
         first = addition/100;
         last = previous.last;
         // Octa is added as the first value
         switch(type){
            case 0:
               triangle = addition;
               break;
            case 1:
               square = addition;
               break;
            case 2:
               penta = addition;
               break;
            case 3:
               hexa = addition;
               break;
            case 4:
               hepta = addition;
               break;
         }
      }

      int Summarum()
      {
         return triangle + square + penta + hexa + hepta + octa;
      }

      bool IsCompatible(int, int);
};

bool Cycle::IsCompatible(int triage, int iteration_depth)
{
   if (iteration_depth == 5){
      if ( triage/100 != last ){
         return 0;
      }
   }
   if ( (triage == triangle) || (triage == square) || (triage == penta) || (triage == hexa) || (triage == hepta) || (triage == octa) ){
      return 0;
   }
   if ( triage%100 != first ){
      return 0;
   }
   return 1;
}

int Iterator(Cycle current, int iteration_depth, int * tri, int * squ, int * pen, int * hex, int * hep, int tril, int squl, int penl, int hexl, int hepl)
{
   int result = 0;
   int i;
   if (!current.triangle){
      for (i = 0; i < tril; i++){
         if (current.IsCompatible(tri[i], iteration_depth)){
            if (iteration_depth == 5){
               result = current.Summarum()+tri[i];
            }else{
               result = Iterator( Cycle(current, tri[i], 0), iteration_depth+1, tri, squ, pen, hex, hep, tril, squl, penl, hexl, hepl);
            }
            if (result){
               return result;
            }
         }
      }
   }
   if (!current.square){
      for (i = 0; i < squl; i++){
         if (current.IsCompatible(squ[i], iteration_depth)){
            if (iteration_depth == 5){
               result = current.Summarum() + squ[i];
            }else{
               result = Iterator( Cycle(current, squ[i], 1), iteration_depth+1, tri, squ, pen, hex, hep, tril, squl, penl, hexl, hepl);
            }
            if (result){
               return result;
            }
         }
      }
   }
   if (!current.penta){
      for (i = 0; i < penl; i++){
         if (current.IsCompatible(pen[i], iteration_depth)){
            if (iteration_depth == 5){
               result = current.Summarum() + pen[i];
            }else{
               result = Iterator( Cycle(current, pen[i], 2), iteration_depth+1, tri, squ, pen, hex, hep, tril, squl, penl, hexl, hepl);
            }
            if (result){
               return result;
            }  
         }  
      }  
   }  
   if (!current.hexa){
      for (i = 0; i < hexl; i++){
         if (current.IsCompatible(hex[i], iteration_depth)){
            if (iteration_depth == 5){
               result = current.Summarum() + hex[i];
            }else{
               result = Iterator( Cycle(current, hex[i], 3), iteration_depth+1, tri, squ, pen, hex, hep, tril, squl, penl, hexl, hepl);
            }
            if (result){
               return result;
            }
         }
      }
   }
   if (!current.hepta){
      for (i = 0; i < hepl; i++){
         if (current.IsCompatible(hep[i], iteration_depth)){
            if (iteration_depth == 5){
               result = current.Summarum() + hep[i];
            }else{
               result = Iterator( Cycle(current, hep[i], 4), iteration_depth+1, tri, squ, pen, hex, hep, tril, squl, penl, hexl, hepl);
            }
            if (result){
               return result;
            }
         }
      }
   }
   return 0;
}

// Starting and ending indices: [45,140], [32,99], [26,81], [23,70], [21,63], [19,58]
int main(void){
   int triangle_amount = 96;
   int square_amount = 68;
   int penta_amount = 56;
   int hexa_amount = 48;
   int hepta_amount = 43;
   int octa_amount = 40;
   int * triangles = new int[triangle_amount];
   int * squares = new int[square_amount];
   int * pentas = new int[penta_amount];
   int * hexas = new int[hexa_amount];
   int * heptas = new int[hepta_amount];
   int truth = 0;
   int i;
   Cycle reused;
   for (i = 0; i < triangle_amount; i++){
      triangles[i] = Triangle(45+i);
   }
   for (i = 0; i < square_amount; i++){
      squares[i] = Square(32+i);
   }
   for (i = 0; i < penta_amount; i++){
      pentas[i] = Penta(26+i);
   }
   for (i = 0; i < hexa_amount; i++){
      hexas[i] = Hexa(23+i);
   }
   for (i = 0; i < hepta_amount; i++){
      heptas[i] = Hepta(21+i);
   }
   for (i = 0; i < octa_amount; i++){
      reused = Cycle(Octa(19+i));
      truth = Iterator( reused, 1, triangles, squares, pentas, hexas, heptas, triangle_amount, square_amount, penta_amount, hexa_amount, hepta_amount );
      if (truth){
         break;
      }
   }
   std::cout << i << " " << truth << "\n";
   delete[] triangles;
   delete[] squares;
   delete[] pentas;
   delete[] hexas;
   delete[] heptas;
}
