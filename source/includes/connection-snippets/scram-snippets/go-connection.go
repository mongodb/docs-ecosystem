// begin scram connection
import "go.mongodb.org/mongo-driver/mongo"

ctx, _ := context.WithTimeout(context.Background(), 10*time.Second)
client, err := mongo.Connect(ctx, options.Client().ApplyURI(
   "mongodb+srv://<username>:<password>@<cluster-url>/test?retryWrites=true&w=majority"
))
if err != nil { log.Fatal(err) }
// end scram connection