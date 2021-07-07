use mongodb::{bson::doc, options::{ClientOptions, ServerApi, ServerApiVersion}, Client};

#[tokio::main]
async fn main() -> mongodb::error::Result<()> {
    // Parse your connection string into an options struct
    let mut client_options = ClientOptions::parse("mongodb://localhost")
            .await?;

    let server_api = ServerApi::builder()
        .version(ServerApiVersion::Version1)
        .build();

    client_options.server_api = Some(server_api);

    // Get a handle to the cluster
    let client = Client::with_options(client_options)?;

    // ...
}
