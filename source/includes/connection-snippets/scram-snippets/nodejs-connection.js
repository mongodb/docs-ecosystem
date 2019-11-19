// begin scram connection
const { MongoClient } = require('mongodb');

const client = new MongoClient(
  'mongodb+srv://<username>:<password>@<cluster-url>/test?retryWrites=true&w=majority'
);

async function run() {
  try {
    await client.connect();
    
    // perform actions using client
  } finally {
    // Ensures that the client will close when you finish/error
    await client.close();
  }
}

run().catch(console.dir);
// end scram connection