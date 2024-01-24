const infoTitle = document.getElementById('info-title');
const user = document.getElementById('username');
const pass = document.getElementById('password');
const cpass = document.getElementById('confirm-password');
const submitInfo = document.getElementById('submit-info');
const switchForm = document.getElementById('switch-form');
const userRegex = /^[A-Za-z]\w{1,9}$/;
const passRegex = /^[A-Za-z0-9\?\!\@\$]{8,24}$/;
// for switching between login prompt and sign up prompt, simple element changes
function switchFormAction() {
    if (switchForm.textContent === `Don't have an account?`) {
        infoTitle.textContent = 'Sign Up';
        cpass.style.display = 'block';
        cpass.required = true;
        submitInfo.textContent = 'Sign Up';
        switchForm.textContent = 'Go back to login';
    } else {
        infoTitle.textContent = 'Login';
        cpass.style.display = 'none';
        cpass.required = false;
        cpass.value = '';
        submitInfo.textContent = 'Login';
        switchForm.textContent = `Don't have an account?`;
    }
}
const userError = document.getElementById('username-error');
const passError = document.getElementById('password-error');
const cpassError = document.getElementById('confirm-password-error');
// change the input boxes based on the current action,
// don't use returns otherwise pass or cpass won't be affected sometimes
function inputAction() {
    if (user.value && userRegex.test(user.value)) {
        user.style.borderColor = '#5db8d7' //blue
        userError.textContent = '';
        userError.style.display = 'none';
    } else {
        user.style.borderColor = '#0f0f0f' //black ish
    }
    if (pass.value && passRegex.test(pass.value)) {
        pass.style.borderColor = '#5db8d7' //blue
        passError.textContent = '';
        passError.style.display = 'none';
    } else {
        pass.style.borderColor = '#0f0f0f' //black ish
    }
    if (cpass.value && passRegex.test(cpass.value) && pass.value === cpass.value) {
        cpass.style.borderColor = '#5db8d7' //blue
        cpassError.textContent = '';
        cpassError.style.display = 'none';
    } else {
        cpass.style.borderColor = '#0f0f0f' //black ish
    }
}
const submitError = document.getElementById('submit-error');
const infoForm = document.getElementById('info-form');
// error checking so todo page doesn't have to do as much
// and prompting user specific errors to help with logining
// or signing up process
function submitInfoAction() {
    if (!user.value || !userRegex.test(user.value)) {
        user.style.borderColor = '#f15249'; //red
        if (!user.value) {
            userError.textContent = 'username is required';
        } else if (!user.value.match(/^[A-Za-z]/)) {
            userError.textContent = 'username needs to start with a letter';
        } else if (!user.value.match(/^.{2,10}$/)) {
            userError.textContent = 'username needs to be 2 to 10 characters long';
        } else {
            userError.textContent = 'username needs to only be letters or numbers';
        }
        userError.style.display = 'block';
        return;
    }
    if (!pass.value || !passRegex.test(pass.value)) {
        pass.style.borderColor = '#f15249'; //red
        if (!pass.value) {
            passError.textContent = 'password is required';
        } else if (!pass.value.match(/^.{8,24}$/)) {
            passError.textContent = 'password needs to be 8 to 24 characters long';
        } else {
            passError.textContent = 'password needs to be letters, numbers, or (?, !, @, $)';
        }
        passError.style.display = 'block';
        return;
    }
    if (cpass.required) {
        if (!cpass.value || !passRegex.test(cpass.value) || pass.value !== cpass.value) {
            cpass.style.borderColor = '#f15249'; //red
            if (!cpass.value) {
                cpassError.textContent = 'confirm password is required';
            } else if (!cpass.value.match(/^.{8,24}$/)) {
                cpassError.textContent = 'confirm password needs to be 8 to 24 characters long';
            } else if (pass.value !== cpass.value) {
                cpassError.textContent = 'confirm password needs to match password';
            } else {
                cpassError.textContent = 'confirm password needs to be letters, numbers, or (?, !, @, $)';
            }
            cpassError.style.display = 'block';
            return;
        }
    }
    infoForm.submit()
}