class Vector{
public:
    Vector(double v[], int dim){
        _dim = dim;
        _v = new double[dim];
        for (int i = 0; i < dim; i++)
            _v[i] = v[i];
    }

    double * _v;
    int _dim;
};
