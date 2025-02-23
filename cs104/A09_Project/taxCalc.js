function capture1(){
    let age;
    let ageradio = document.getElementsByName('age');
    for(let i=0;i<ageradio.length;i++){
        if(ageradio[i].checked){
            age = ageradio[i].value;
            break;
        } else{
            age = '';
        }
    }
    let _name = document.getElementById("name").value;
    let regex = new RegExp("^[a-zA-Z ]*$");
    if (age=='') alert("Issue\n-> Select your age group");
    else if(regex.test(_name)==false && age=='') alert("Issues\n-> Name should contain only letters.\n-> Select your age group");
    else if(regex.test(_name)==false) alert("Issues\n-> Name should contain only letters.");
    else{
        if(_name.length==0){
            let check1 = confirm("Are you sure to keep the name empty? The result will be made for a User.");
            if(check1) _name="User";
        }
        if(_name.length!=0){
            localStorage.setItem('name',_name);
            localStorage.setItem('age',age);
            let check = confirm("Are you sure?\nName: "+localStorage.getItem('name')+"\nAge Group: "+localStorage.getItem('age'));
            if(check) window.location.href = ".\\page2.html";
        }
    }
};

function return1(){
    let check = confirm("Undo operations?");
    if(check) window.location.href = ".\\page1.html";
}

function capture2(){
    let inputVals = document.getElementsByTagName('input');
    let values = "";
    for(let i=0;i<inputVals.length;i++){
        if(inputVals[i].value=='') inputVals[i].value=0;
        values = values.concat(inputVals[i].name,': ',inputVals[i].value,'\n');
    }
    let income = Number(inputVals[0].value) + Number(inputVals[2].value) + Number(inputVals[4].value) + Number(inputVals[6].value) + Number(inputVals[7].value);
    localStorage.setItem('totalIncome',income);
    localStorage.setItem('exemptAllowances',inputVals[1].value);
    localStorage.setItem('interestIncome',inputVals[2].value);
    localStorage.setItem('interestHomeLoanSO',inputVals[3].value);
    localStorage.setItem('interestHomeLoanLO',inputVals[5].value);
    let check = confirm("Are you sure?\n"+values);
    if(check) window.location.href = ".\\page3.html";

}

function return2(){
    let check = confirm("Go to the previous page?");
    if(check) window.location.href = ".\\page2.html";
}

function capture3(){
    let inputVals = document.getElementsByTagName('input');
    let values = "", deductions = 0;
    for(let i=0;i<inputVals.length;i++){
        if(inputVals[i].value=='') inputVals[i].value=0;
        values = values.concat(inputVals[i].name,': ',inputVals[i].value,'\n');
    }
    if(Number(inputVals[0].value) > 150000) inputVals[0].value = "150000";
    if(Number(inputVals[1].value) > Number(localStorage.getItem('interestIncome'))) inputVals[1].value = localStorage.getItem('interestIncome');
    if(Number(inputVals[1].value) > 10000) inputVals[1].value = "10000";
    if(Number(inputVals[2].value) > 75000) inputVals[2].value = "75000";
    if(Number(inputVals[5].value) > 150000) inputVals[5].value = "150000";
    if(Number(inputVals[6].value) > 200000) inputVals[6].value = "200000";
    for(let i=0;i<inputVals.length;i++){
        deductions += Number(inputVals[i].value)
    }
    if(deductions > Number(localStorage.getItem('totalIncome'))) deductions = Number(localStorage.getItem('totalIncome'));
    localStorage.setItem('totalDeductions',deductions);
    let check = confirm("Are you sure?\n"+values);
    if(check) window.location.href = ".\\page4.html";
}

function upgrades(){
    document.getElementById("O_totalIncome").innerHTML = localStorage.getItem('totalIncome');
    document.getElementById("N_totalIncome").innerHTML = localStorage.getItem('totalIncome');
    document.getElementById("O_exemptAllowances").innerHTML = localStorage.getItem('exemptAllowances')
    if(localStorage.getItem('totalIncome') - localStorage.getItem('totalDeductions') < 50000){
        document.getElementById("O_standard").innerHTML = localStorage.getItem('totalIncome') - localStorage.getItem('totalDeductions');
        document.getElementById("N_standard").innerHTML = localStorage.getItem('totalIncome') - localStorage.getItem('totalDeductions');
    } else{
        document.getElementById("O_standard").innerHTML = 50000
        document.getElementById("N_standard").innerHTML = 50000
    }
    standard = document.getElementById("O_standard").innerHTML;
    document.getElementById("O_VIA").innerHTML = localStorage.getItem('totalDeductions');
    var O_taxable = localStorage.getItem("totalIncome") - localStorage.getItem("exemptAllowances") - localStorage.getItem('totalDeductions') - standard;
    document.getElementById("O_taxable").innerHTML = O_taxable;
    var N_taxable = localStorage.getItem("totalIncome") - standard;
    document.getElementById("N_taxable").innerHTML = N_taxable;
    var O_ctax, N_ctax;
    if(localStorage.getItem('age')=='0-60'){
        if(O_taxable <= 250000) O_ctax = 0;
        else if(O_taxable <= 500000) O_ctax = O_taxable*0.05 - 12500;
        else if(O_taxable <= 1000000) O_ctax = O_taxable*0.2 - 87500;
        else O_ctax = O_taxable*0.3 - 187500;
    } else if(localStorage.getItem('age')=='60-80'){
        if(O_taxable <= 300000) O_ctax = 0;
        else if(O_taxable <= 500000) O_ctax = O_taxable*0.05 - 15000;
        else if(O_taxable <= 1000000) O_ctax = O_taxable*0.2 - 90000;
        else O_ctax = O_taxable*0.3 - 190000;
    } else{
        if(O_taxable <= 500000) O_ctax = 0;
        else if(O_taxable <= 1000000) O_ctax = O_taxable*0.2 - 100000;
        else O_ctax = O_taxable*0.3 - 200000;
    }
    if(N_taxable <= 300000) N_ctax = 0;
    else if(N_taxable <= 600000) N_ctax = N_taxable*0.05 - 15000;
    else if(N_taxable <= 900000) N_ctax = N_taxable*0.1 - 45000;
    else if(N_taxable <= 1200000) N_ctax = N_taxable*0.15 - 90000;
    else if(N_taxable <= 1500000) N_ctax = N_taxable*0.2 - 150000;
    else N_ctax = N_taxable*0.3 - 300000;
    document.getElementById("O_ctax").innerHTML = O_ctax;
    document.getElementById("N_ctax").innerHTML = N_ctax
    document.getElementById("O_4per").innerHTML = O_ctax*0.04;
    document.getElementById("N_4per").innerHTML = N_ctax*0.04;
    document.getElementById("O_ftax").innerHTML = O_ctax*1.04;
    document.getElementById("N_ftax").innerHTML = N_ctax*1.04;
    document.getElementById("name").innerHTML = localStorage.getItem("name");
    if(O_ctax >= N_ctax){
        document.getElementById("suggestion").innerHTML = "New";
        document.getElementById("benefit").innerHTML = (O_ctax - N_ctax)*1.04;
    } else{
        document.getElementById("suggestion").innerHTML = "Old";
        document.getElementById("benefit").innerHTML = (N_ctax - O_ctax)*1.04;
    }
}