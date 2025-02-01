Endless Cakes! The story that never ends… The application simulates an automatic cake-making machine with unlimited resources. Its main role is to serve the customer with the desired cake. On the other hand, the customer will have a main menu that provides them with certain selection options. Below, we will explore the complete architecture of our application. Keep in mind that the application simulates the creation of cakes on demand… endlessly 😊. The following components are identified:

- **Command Panel**: This component is the interface with the customer. Since this is a simulation, it will be a CLI (command line interface). It will contain all the necessary functions to fulfill the customer's requests.

- **Command Taker**: This component takes the order from the CommandPanel. It communicates with both the CakeMaker and the CarouselOfCakes.

  - The functionality of the CommandTaker is to fulfill the customer's orders. It manages them according to its functionality, which is: when it receives an order from the CommandPanel, fulfilling the order involves checking if the product is available in the CarouselOfCakes (mini storage). If it exists, it will be removed from the CarouselOfCakes and delivered to the customer. If it is not in the CarouselOfCakes, it will request the CakeMaker to fulfill the order.

- **CarouselOfCakes**: This is a cake storage. It has a maximum capacity of 12 cakes. It will only accept items of type Cake. This aspect will be addressed later in the project.

- **CakeMaker**: This is the one who makes the cake. It creates a cake within a specified time interval according to the recipe.

### CommandPanel

**Class attributes**: List of recipes and the CommandPanel component.

**Functionalities**:
- `showProducts()`: Displays all the products available for purchase.
- `selectProduct(name: string)`: Selects the desired product from the menu and forwards it to the CommandTaker to process the order.
- `selectProduct(name: string, nrOfProducts: int)`: An overloaded version of the above method, specifying the quantity of the desired product.
- `showProductsInCarousel()`: Displays in the console the products currently in the circular storage (CarouselOfCakes).

### CommandTaker

**Class attributes**: CarouselOfCakes – which holds the most frequently purchased cakes, CakeMaker – the one who makes the cakes, CakeRecipe – the list of ready-made cakes.

**Functionalities**:
- `takeCommand(recipe: CakeRecipe): Cake`: Takes the order from the CommandPanel and forwards it to the CakeMaker. Before doing so, it checks if the cake is available in the CarouselOfCakes. If the desired product is there, it will be taken directly from there.
- `takeCommand(recipe: CakeRecipe, nrOfCakes): Array[Cake]`: Takes the order in case multiple cakes are requested. If a quantity of products is required, it will directly request the CakeMaker.
- `getCakesFromCarousel(): Array[Cake]`: Returns the list of cakes currently in the CarouselOfCakes.
- `checkCarouselOfCakes(): bool`: Checks the current capacity of the CarouselOfCakes.
- `refillCarousel(): void`: If the capacity in the Carousel is low, this method will request the CakeMaker to make as many cakes as needed to fill the CarouselOfCakes to its maximum capacity.

### CakeMaker

**Class attributes**: None.

**Class functions**:
- `takeCommand(recipe: RecipeCake): Cake`: This method simulates the creation of a cake. For each recipe received, it waits for 5 seconds and then returns an object of type Cake. It takes the name from the recipe.

![image](https://user-images.githubusercontent.com/104904530/200133009-d2d69545-20e6-44e5-9cd0-03afb106816f.png)

The image content describes the class structure and relationships in the "Endless Cakes" application. Here's an explanation in English:

1. **Cake Class**:
   - **Attributes**: 
     - `name: char[]` - The name of the cake.
   - **Methods**:
     - `Cake(name: char[])` - Constructor to initialize the cake with a name.
     - `getName(): char[]` - Returns the name of the cake.

2. **CakeMaker Class**:
   - **Methods**:
     - `CakeMaker()` - Constructor.
     - `takeCommand(recipe: RecipeCake): Cake` - Takes a recipe and returns a Cake object after simulating the baking process.

3. **CommandTaker Class**:
   - **Attributes**:
     - `carouselRecipe: RecipeCake` - The recipe for cakes in the carousel.
     - `cakeMaker: CakeMaker` - Instance of CakeMaker to bake cakes.
     - `carousel: CarouselOfCakes` - The storage for cakes.
   - **Methods**:
     - `CommandTaker()` - Constructor.
     - `takeCommand(recipe: RecipeCake): Cake` - Takes a recipe and processes the order.
     - `takeCommand(recipe: RecipeCake, nrOfCakes: int): Array(Cake)` - Takes multiple cake orders.
     - `takeCommand(nameOfCake: string): Cake` - Takes an order by cake name.
     - `getCakesFromCarousel(): Array(Cake)` - Returns the list of cakes in the carousel.
     - `checkCarouselOfCakes(): bool` - Checks the current state of the carousel.
     - `refillCarousel(): bool` - Refills the carousel if necessary.

4. **CommandPanel Class**:
   - **Attributes**:
     - `menu: List<CakeRecipe>` - The list of available cake recipes.
     - `commandTaker: CommandTaker` - Instance of CommandTaker to handle orders.
   - **Methods**:
     - `CommandPanel()` - Constructor.
     - `showProducts(): void` - Displays available products.
     - `selectProduct(name: string): void` - Selects a product by name.
     - `selectProduct(name: string, numberOfProducts: int): void` - Selects multiple products.
     - `showProductsInCarousel(): void` - Displays products in the carousel.

5. **RecipeCake Class**:
   - **Attributes**:
     - `name: string` - The name of the recipe.
     - `time: int` - The time required to prepare the cake.
   - **Methods**:
     - `Cake(name: string, time: int)` - Constructor to initialize the recipe.
     - `getName(): string` - Returns the name of the recipe.
     - `getTime(): int` - Returns the preparation time.

The relationships between these classes include:
- **Dependency**: Indicates that one class depends on another.
- **Composition**: Represents a strong relationship where one class is composed of another.
- **Association**: Represents a relationship where one class is associated with another.

This structure outlines how the different components of the application interact to fulfill cake orders, manage the carousel, and handle the baking process.

![image](https://user-images.githubusercontent.com/104904530/200133129-c5951e96-0d78-46c4-ac8d-3cf9298ae761.png)

The image appears to represent the architecture of the "Endless Cakes" application, illustrating the relationships between the main components:

1. **Client**: The end-user who interacts with the application to order cakes.
2. **Command Panel**: The interface through which the client places orders. It provides options for selecting cakes and viewing available products.
3. **Command Taker**: This component processes the orders received from the Command Panel. It checks the availability of cakes in the CarouselOfCakes and communicates with the CakeMaker if additional cakes need to be prepared.
4. **CarouselOfCakes**: A storage unit that holds up to 12 cakes. It serves as a quick-access repository for frequently requested cakes.
5. **CakeMaker**: The component responsible for baking new cakes based on the recipes provided. It ensures that the CarouselOfCakes is replenished as needed.

This diagram visually summarizes the flow of operations in the application, from the client's request to the fulfillment of the order, either directly from the CarouselOfCakes or via the CakeMaker.
