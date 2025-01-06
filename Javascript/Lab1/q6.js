var orders = [
  {
    orderId: "ORD001",
    customer: "John Doe",
    items: "item1:2,item2:1,item3:5",
    orderDate: "2023-12-01",
    deliveryDate: "2023-12-05",
    deliveryAddress: "123, Main Street, Springfield, USA",
  },
  {
    orderId: "ORD002",
    customer: "Jane Smith",
    items: "itemA:3,itemB:4",
    orderDate: "2023-11-15",
    deliveryDate: "2023-11-20",
    deliveryAddress: "Flat 4B, Elmwood Apartments, New York, USA",
  },
  {
    orderId: "ORD003",
    customer: "Alice Johnson",
    items: "itemX:1",
    orderDate: "2023-10-10",
    deliveryDate: "2023-10-15",
    deliveryAddress: "456, Pine Lane, Denver, USA",
  },
];

orders = orders.map((x) => {
  var [buildingNumber, deliveryStreet, deliveryCity, deliveryCountry] = x.deliveryAddress.split(",").map((x) => x.trim());
  return {
    orderId: x.orderId,
    customer: x.customer,
    totalItems: x.items.split(",").reduce((prev, next) => prev + parseInt(next.split(":")[1]), 0),
    orderDate: x.orderDate,
    deliveryDate: x.deliveryDate,
    deliveryDuration: (new Date(x.deliveryDate) - new Date(x.orderDate)) / (1000 * 60 * 60 * 24),
    deliveryCountry,
    deliveryCity,
    deliveryStreet,
    buildingNumber,
  };
});

console.log(orders);
