#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

int main()
{ 
  try
  {
     // Create an instance.
     mongocxx::instance inst{};
  
     // Replace the connection string with your MongoDB deployment's connection string.
     const auto uri = mongocxx::uri{"<connection string>"};
  
     // Setup the connection and get a handle on the database.
     mongocxx::client conn{ uri, client_options};
     mongocxx::database db = conn["test"];
   }

  catch (const std::exception& e) 
  {
     // Handle errors.
     std::cout<< e.what() << std::endl;
   }

  return 0;
}

