let x=10;
console.log("gia tri cua x la: ",x);
let y=10;
console.log("gia tri cua y la: ", y);
//CHUYỂN KIỂU DỮ LIỆU 
let bool = true;
let num4 = Number(bool);
let strPI = "3.14";
let num2 = parseFloat(strPI);

//kIỂU SỐ
//STRING
 let lang = "javasript"
 let lang2 = "javascript"

 let strTB= `ngon ngu ${lang} rat de hoc`;

 console.log (strTB);

 let a = [1,2,3,4,5,6]
 a.splice(2,0,9);
 console.log(a)

 //trừ 2 ngày 
 const dtNow = new Date();
 console.log("Ngay hien tai:" , dtNow);

 const dt = new Date(2023,8-1,20);
 console.log("Ngay cu the:", dt);
//khoang cach giua 2 ngay
const Time = dt.getTime()- dtNow.getTime();
const Days= Time / (1000*3600*24);
console.log("Khoang cach giua 2 ngay laf :" ,Days,"ngay");