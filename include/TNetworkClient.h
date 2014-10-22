#ifndef ___TAgileClient
#define ___TAgileClient

#include <sstream>
#include "TObject.h"

// by Joshua Loyal (22-10-2014)

class TNetworkClient : public TObject
{
    public:
        TNetworkClient();
        TNetworkClient(const std::string &filename);
        ~TNetworkClient() = default;
        void load(const std::string &filename);
        void load(std::stringstream &s);
        std::map<std::string, double> predict(const std::map<std::string, double> &x);

        std::vector<std::string> inputs();

    private:
        TTrainedDeepNetwork net;

        ClassDef( TNetworkClient, 1 )
};

TNetworkClient::TNetworkClient() {}

TNetworkClient::TNetworkClient(const std::string &filename)
{
    net.from_yaml(filename);
}

inline void TNetworkClient::load(const std::string &filename)
{
    net.from_yaml(filename)
}

inline void TNetworkClient::load(std::stringstream &s)
{
    net.from_yaml(s);
}

inline std::map<std::string, double> TNetworkClient::predict(const std::map<std::string, double> &x)
{
    return std::move(net.predict_map(x));
}

inline std::vector<std::string> TNetworkClient::inputs()
{
    return net.get_inputs();
}
#endif
