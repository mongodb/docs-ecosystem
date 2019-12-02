// begin scram connection
const { MongoClient } = require('mongodb');

const client = new MongoClient(
  'mongodb+srv://<username>:<password>@<cluster-url>/test?retryWrites=true&w=majority'
);

async function run() {
  try {
    await client.connect();
    const database = client.db("testDB");
    var collection = database.collection("testCol");
    const docCount = collection.countDocuments({});
    console.log(docCount);
    // perform actions using client
  } finally {
    // Ensures that the client will close when you finish/error
    await client.close();
  }
}

run().catch(console.dir);
// end scram connection