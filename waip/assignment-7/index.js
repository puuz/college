// Sam Farris
// CS248_001
// 11/15/2023

// add br element inbetween container and input so elements are spread out evenly and not touching eachother
function addSpace(container) {
    container.insertAdjacentElement('afterend', document.createElement('br'));
}

let container;
const addText = document.getElementById('add_text');
const changeText = document.getElementById('change_text');
changeText.disabled = true;
let customText;
let input;
// event listener for adding text and allowing for changing text in newly added custom text element
addText.addEventListener('click', function() {
    this.disabled = true;

    container = document.getElementById('container1');

    customText = document.createElement('p');
    container.appendChild(customText);

    input = document.createElement('input');
    input.type = 'text';
    container.appendChild(input);
    addSpace(container);

    changeText.disabled = false;
});
// event listener for changing text and setting the value to whatever the input is at the moment
changeText.addEventListener('click', function() {
    customText.innerHTML = input.value;
});

const date = document.getElementById('date');
const displayDate = document.getElementById('display_date');
// event listener for setting current date displayed as locale string with 1 second cooldown
displayDate.addEventListener('click', function() {
    this.disabled = true;
    date.innerHTML = new Date().toLocaleString();
    setTimeout(() => this.disabled = false, 1000);
});

const createImg = document.getElementById('create_img');
const setImg = document.getElementById('set_img');
setImg.disabled = true;
let src;
let img;
// event listener for adding image and allowing for changing image in newly added custom image element
createImg.addEventListener('click', function() {
    this.disabled = true;

    container = document.getElementById('container2');

    src = document.createElement('input');
    src.type = 'text';
    container.appendChild(src);
    addSpace(container);

    container = document.getElementById('container3');

    img = document.createElement('img');
    img.alt = `You've created the image element, now just add the image source! (Ex: mortalkombat.png, princessbride.png, tmnt.png, etc)`;
    img.className = 'custom_image';
    container.appendChild(img);
    addSpace(container);

    setImg.disabled = false;
});
// event listener for changing image source and setting the value to whatever the source input is at the moment with 1 second cooldown
setImg.addEventListener('click', function() {
    this.disabled = true;
    img.setAttribute('src', src.value);
    setTimeout(() => this.disabled = false, 1000);
});