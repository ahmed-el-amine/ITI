/**
 * @typedef {Function} priceAfterDiscount
 * @param {number} price
 * @param {number} discount
 * @returns {number}
 */

function priceAfterDiscount(price, discount) {
  // check if price and discount is valid numbers
  const priceState = isValidInt(price);
  const discountState = isValidInt(discount);

  if (!priceState.status || !discountState.status) {
    throw Error("Please Provide a valid params");
  }

  if (priceState.value <= 0) throw Error("Please provide price large than 0");
  if (discountState.value < 0 || discountState.value > 100) throw Error("Please provide discount from 0 to 100");

  // handle Discounted Price
  const discountedPrice = price - price * (discount / 100);

  return discountedPrice;
}

/**
 * @typedef {Function} isValidInt
 * @param {number} value
 * @returns {{ status: boolean, value: number }}
 */
function isValidInt(value) {
  if (!isNaN(parseInt(value))) return { status: true, value: parseInt(value) };
  return { status: false, value: 0 };
}

console.log(priceAfterDiscount(100, 10));
