#ifndef ___TTrainedDeepNetwork
#define ___TTrainedDeepNetwork

#include "TObject.h"
#include "TMatrixD.h"
#include "TVectorD.h"
#include <math.h>

// by Joshua Loyal (22-10-2014)

namespace deepnet {
    
    class TLayer : public TObject
    {

    };

    class TTrainedDeepNetwork : public TObject
    {
        public:
            TTrainedDeepNetwork();

        private:
            ClassDef( TTrainedDeepNetwork, 1 )
    };
}


#endif
