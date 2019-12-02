// begin scram connection
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>

using bsoncxx::builder::basic::kvp;

int main(int, char**) {

mongocxx::instance inst{}; 
auto client = mongocxx::client conn{
   mongocxx::uri{
      "mongodb+srv://<username>:<password>@<cluster-url>/test?retryWrites=true&w=majority"
   }
};

mongocxx::database db = client["testDB"];
mongocxx::collection collection = db["testCol"];
bsoncxx::builder::basic::document basic_builder{};
basic_builder.append(kvp("", ""));
bsoncxx::document::value filter = basic_builder.extract();
collection.count_documents(client, filter);

}
// end scram connection