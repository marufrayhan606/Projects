#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Define data structures for crops and orders
typedef struct {
    char name[100];
    char description[500];
    double price;  // Price per kg
    int quantity;  // Available stock in kg
    char image[200]; // Assuming image filenames
} Crop;

typedef struct {
    int order_id;
    Crop crops[100]; // Assuming maximum 100 items per order
    int quantities[100]; // Quantities of each crop
    int num_items; // Number of items in the order
    double total_price;
} Order;

// Predefined list of crops
void loadCropData(Crop crops[], int *numCrops) {
    Crop predefinedCrops[] = {
        {"Rice", "High quality rice.", 50.0, 100, "rice.jpg"},
        {"Corn", "Fresh corn.", 20.0, 150, "corn.jpg"},
        {"Jute", "Jute for making fibers.", 10.0, 200, "jute.jpg"},
        {"Sugarcane", "Sweet sugarcane.", 25.0, 100, "sugarcane.jpg"},
        {"Wheat", "Organic wheat.", 45.0, 120, "wheat.jpg"},
        {"Peas", "Fresh peas.", 15.0, 80, "peas.jpg"},
        {"Mustard", "Organic mustard seeds.", 30.0, 90, "mustard.jpg"},
        {"Brinjal", "Fresh brinjal.", 12.0, 110, "brinjal.jpg"},
        {"Mango", "Delicious mangoes.", 60.0, 50, "mango.jpg"},
        {"Potato", "Fresh potatoes.", 22.0, 300, "potato.jpg"},
        {"Watermelon", "Juicy watermelon.", 40.0, 60, "watermelon.jpg"},
        {"Cabbage", "Fresh cabbage.", 10.0, 90, "cabbage.jpg"},
        {"Tomato", "Ripe tomatoes.", 12.0, 150, "tomato.jpg"},
        {"Cucumber", "Crunchy cucumber.", 15.0, 130, "cucumber.jpg"},
        {"Carrot", "Fresh carrots.", 18.0, 80, "carrot.jpg"},
        {"Pineapple", "Tropical pineapples.", 55.0, 40, "pineapple.jpg"}
    };

    *numCrops = sizeof(predefinedCrops) / sizeof(predefinedCrops[0]);
    for (int i = 0; i < *numCrops; i++) {
        crops[i] = predefinedCrops[i];
    }
}

// Display crop list
void displayCropList(Crop crops[], int numCrops) {
    printf("Available Crops for Sale (Price per kg in Taka):\n");
    for (int i = 0; i < numCrops; i++) {
        printf("%d. %s - %s | Price: %.2f Taka/kg | Available: %d kg\n", i + 1, crops[i].name, crops[i].description, crops[i].price, crops[i].quantity);
    }
}

// Add crop to cart
void addToCart(Crop *cart, int *cartSize, Crop crop, int quantity) {
    if (quantity > crop.quantity) {
        printf("Not enough stock available for %s.\n", crop.name);
        return;
    }
    for (int i = 0; i < *cartSize; i++) {
        if (strcmp(cart[i].name, crop.name) == 0) {
            printf("Crop already in cart.\n");
            return;
        }
    }
    cart[*cartSize] = crop;
    cart[*cartSize].quantity = quantity; // Set the quantity in the cart
    (*cartSize)++;
    printf("%s added to the cart.\n", crop.name);
}

// Remove crop from cart
void removeFromCart(Crop *cart, int *cartSize, int index) {
    if (index >= *cartSize || index < 0) {
        printf("Invalid item index.\n");
        return;
    }
    for (int i = index; i < (*cartSize) - 1; i++) {
        cart[i] = cart[i + 1];
    }
    (*cartSize)--;
    printf("Item removed from the cart.\n");
}

// Calculate total price
double calculateTotalPrice(Crop *cart, int cartSize) {
    double total = 0;
    for (int i = 0; i < cartSize; i++) {
        total += cart[i].price * cart[i].quantity;
    }
    return total;
}

// Display items in the cart
void viewCart(Crop *cart, int cartSize) {
    if (cartSize == 0) {
        printf("Your cart is empty.\n");
        return;
    }
    printf("Your Cart:\n");
    for (int i = 0; i < cartSize; i++) {
        printf("%d. %s | Price: %.2f Taka/kg | Quantity: %d kg\n", i + 1, cart[i].name, cart[i].price, cart[i].quantity);
    }
    printf("Total Price: %.2f Taka\n", calculateTotalPrice(cart, cartSize));
}

// Place order process
void placeOrder(Crop *cart, int cartSize) {
    if (cartSize == 0) {
        printf("Your cart is empty. Add items before placing the order.\n");
        return;
    }
    double total = calculateTotalPrice(cart, cartSize);
    printf("Placing order...\n");
    printf("Order Summary:\n");
    for (int i = 0; i < cartSize; i++) {
        printf("%s | Quantity: %d kg | Price: %.2f Taka/kg\n", cart[i].name, cart[i].quantity, cart[i].price);
    }
    printf("Total Amount to Pay: %.2f Taka\n", total);
    printf("Order placed successfully!\n");
    // Save order logic can be implemented here
}

// Main function
int main() {
    Crop crops[100];
    int numCrops = 0;
    Crop cart[100];
    int cartSize = 0;

    // Load crop data
    loadCropData(crops, &numCrops);

    // Main menu loop
    while (true) {
        printf("\n1. Browse Crops\n");
        printf("2. View Cart\n");
        printf("3. Add to Cart\n");
        printf("4. Remove from Cart\n");
        printf("5. Place Order\n");
        printf("6. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayCropList(crops, numCrops);
                break;
            case 2:
                viewCart(cart, cartSize);
                break;
            case 3: {
                int cropIndex, quantity;
                printf("Enter the crop number to add to cart: ");
                scanf("%d", &cropIndex);
                if (cropIndex < 1 || cropIndex > numCrops) {
                    printf("Invalid crop selection.\n");
                    break;
                }
                printf("Enter quantity (in kg): ");
                scanf("%d", &quantity);
                addToCart(cart, &cartSize, crops[cropIndex - 1], quantity);
                // Automatically view the cart after adding to cart
                viewCart(cart, cartSize);
                break;
            }
            case 4: {
                int cartIndex;
                viewCart(cart, cartSize);
                printf("Enter the cart item number to remove: ");
                scanf("%d", &cartIndex);
                removeFromCart(cart, &cartSize, cartIndex - 1);
                break;
            }
            case 5:
                placeOrder(cart, cartSize);
                break;
            case 6:
                printf("Thank you for using the system!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
