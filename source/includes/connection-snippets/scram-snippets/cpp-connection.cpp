// begin scram connection
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

mongocxx::instance inst{}; 
mongocxx::client conn{
   mongocxx::uri{
      "mongodb+srv://<username>:<password>@<cluster-url>/test?retryWrites=true&w=majority"
   }
};
mongocxx::database db = conn["test"];
// end scram connection