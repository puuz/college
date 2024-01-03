const STATE_REGEX = /^[A-Z]{2}$|^[a-z]{2}$/;
const ZIP_REGEX = /^[0-9]{5}$/;

function submitForm() {
    let firstnamelabel = document.getElementById('firstnamelabel');
    let firstname = document.getElementById('firstname');

    let lastnamelabel = document.getElementById('lastnamelabel');
    let lastname = document.getElementById('lastname');

    let streetlabel = document.getElementById('streetlabel');
    let street = document.getElementById('street');

    let citylabel = document.getElementById('citylabel');
    let city = document.getElementById('city');

    let state = document.getElementById('state');
    let zip = document.getElementById('zip');

    let items = document.getElementsByClassName('items');
    let noitemselected = true;

    let cc = document.getElementsByName('credit');
    let noccselected = true;

    let orderform = document.forms['orderform'];

    // looping over nodes that have items class whether the item is checked or not
    // and breaking once one item is found checked
    for (let i = 0; i < items.length; i++) {
        if (items[i].checked) {
            noitemselected = false;
            break;
        }
    }

    // same looping as before except this is for credit card selection
    for (let i = 0; i < cc.length; i++) {
        if (cc[i].checked) {
            noccselected = false;
            break;
        }
    }

    if (firstname.value) firstnamelabel.style.color = 'white';
    if (lastname.value) lastnamelabel.style.color = 'white';
    if (street.value) streetlabel.style.color = 'white';
    if (city.value) citylabel.style.color = 'white';

    if (noitemselected) alert('Please select at least one item')
    else if (!firstname.value) firstnamelabel.style.color = 'red';
    else if (!lastname.value) lastnamelabel.style.color = 'red';
    else if (!street.value) streetlabel.style.color = 'red';
    else if (!city.value) citylabel.style.color = 'red';
    // regex testing on state and zip strings whether it contains 2 letters and 5 numbers
    else if (!STATE_REGEX.test(state.value)) alert('State must contain 2 letters');
    else if (!ZIP_REGEX.test(zip.value)) alert('Zip must contain 5 numbers');
    else if (noccselected) alert('Please select a credit card');
    else {
        if (confirm('Are you ready to place your order?')) {
            //submit document.form of orderforms causing a post request to ordersummary.php
            orderform.submit();
        }
    }
}