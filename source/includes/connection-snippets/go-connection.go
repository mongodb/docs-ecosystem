package main

import "go.mongodb.org/mongo-driver/mongo"

func main() {

	// Replace the uri string with your MongoDB deployment's connection string.
	uri := "mongodb+srv://<username>:<password>@<cluster-address>/test?w=majority"

	ctx, _ := context.WithTimeout(context.Background(), 10*time.Second)

	client, err := mongo.Connect(ctx, options.Client().ApplyURI(uri))
	if err != nil {
		log.Fatal(err)
	}

	// Ping the primary
	if err := client.Ping(ctx, readpref.Primary()); err != nil {
		panic(err)
	}

	// Defer a function call to Disconnect and check for an error in case the
	// application logs a warning instead of a panic.
	defer func() {
		if err = client.Disconnect(ctx); err != nil {
			panic(err)
		}
	}()
}
