// 2. Създайте функция greetingTemp ( greeting),  където параметърът  
//greeting   е  желания поздрав – „добро утро”,
//  „добър ден” и т.н. Функцията  greetingTemp()   да връща като резултат 
//вложената в нея  функция greetingPers . greetingPers(name)  приема 1 параметър – името на лицето,
// и извежда персонализиран поздрав във вида „Добро утро, Иван! ”

// Създайте 2 променливи ( примерно, morning и evening)  със значения  резултатите от извикването на greetingTemp() със съответния параметър. Изведете с тяхна помощ персонализирани поздрави.​

console.log('Zadacha 2')

function greetingTemp(greeting) {
    var fIndex = 0;

    // shte zameni v simvola na purvata poziciq ot greetings 
    // s glaven simvol
    greeting = greeting.replace(greeting.charAt(fIndex), greeting.charAt(fIndex).toUpperCase())

    var exclamationMark = '!';


    function greetingPers(name) {
        var fullGreeting = '';
        var comma = ', ';
        // vrushta  svurzan strling s pozdrav zapetaq ime i '!'
        return fullGreeting.concat(greeting, comma, name, exclamationMark);

    }

    // vrushta suobjenieto fullGreetings 
    return greetingPers
}


var greetings = ['добър ден', 'добро утро', 'Hello world'];
var myName = 'Иван';

greetings.forEach(element => {
    console.log(greetingTemp(element)(myName));
})
