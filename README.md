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

![image](https://user-images.githubusercontent.com/104904530/200133129-c5951e96-0d78-46c4-ac8d-3cf9298ae761.png)
