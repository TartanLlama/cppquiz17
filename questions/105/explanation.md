The Standard says this about jump statements:

[stmt.jump]§6.6¶2 Transfer [...] back past an initialized variable with automatic storage duration involves the destruction of variables with automatic storage duration that are in scope at the point transferred from but not at the point transferred to.