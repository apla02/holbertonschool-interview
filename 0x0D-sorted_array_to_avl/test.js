function pakiman(vida)
{
    vida = vida + vida;
    vida++;
    return vida;
}
var vida = 2;
vida = pakiman(vida);
console.log(vida);
