
class Polyx
{
   private:
      double *a;
      int n;

   public:
      Polyx( double coefficient[], int terms );
      Polyx( const Polyx& p );
      ~Polyx();
      double f( double x ) const;
};

