import hikari
import lightbulb

bot=lightbulb.BotApp(
    token="OTUwMTEyMTU1NTE1MTEzNDcy.YiUK5g.7gMlllrtyNHhLzTsrBIAInQWoZs",
    default_enabled_guilds=(811409993286156319)
    )

@bot.listen(hikari.StartedEvent)
async def welcome(event):
    print("YA DESPERTÓ MÉXICO CULEROS C:")

@bot.listen(hikari.GuildMessageCreateEvent)
async def p_mess(event):
    print(event.content)


@bot.listen()
async def ping(event: hikari.GuildMessageCreateEvent) -> None:
    # If a non-bot user sends a message "hk.ping", respond with "Pong!"
    # We check there is actually content first, if no message content exists,
    # we would get `None' here.
    if event.is_bot or not event.content:
        return

    if event.content.startswith("hk.ping"):
        await event.message.respond("Pong!")

@bot.listen()
async def omg(event: hikari.GuildMessageCreateEvent) -> None:
    if event.is_bot or not event.content:
        return

    if event.content.startswith("omg"):
        await event.message.respond("OOOOOOOOMAAAAAAAAAAAAAAAAAIIIIIIIIIIIIIIGOOOOOOOOOOOOOOOOD")

@bot.listen()
async def OMG(event: hikari.GuildMessageCreateEvent) -> None:
    if event.is_bot or not event.content:
        return

    if event.content.startswith("OMG"):
        await event.message.respond("OOOOOOOOMAAAAAAAAAAAAAAAAAIIIIIIIIIIIIIIGOOOOOOOOOOOOOOOOD")

@bot.listen()
async def wtf(event: hikari.GuildMessageCreateEvent) -> None:
    if event.is_bot or not event.content:
        return

    if event.content.startswith("wtf"):
        await event.message.respond("WTF BROOOOOOOOOO")

@bot.listen()
async def SEXO(event: hikari.GuildMessageCreateEvent) -> None:
    if event.is_bot or not event.content:
        return

    if event.content.startswith("sexo"):
        await event.message.respond("PARA SEXO GRATIS CONTACTA: https://www.facebook.com/diego.hernandez.105")

@bot.listen()
async def inmortal(event: hikari.GuildMessageCreateEvent) -> None:
    if event.is_bot or not event.content:
        return

    if event.content.startswith("inmortal"):
        await event.message.respond("\n -creo que soy inmortal\n -ARGUMENTA, ARGUMENTA TU PENDEJADA, ARGUMENTAAAAAAAAAAAAAAAAAAAAA\n-pues no he muerto\n-fascinante")


@bot.listen()
async def rommel(event: hikari.GuildMessageCreateEvent) -> None:
    if event.is_bot or not event.content:
        return

    if event.content.startswith("rommel"):
        await event.message.respond("se la come ajajajaaj que pendejo")

@bot.listen()
async def llanta(event: hikari.GuildMessageCreateEvent) -> None:
    if event.is_bot or not event.content:
        return

    if event.content.startswith("llanto"):
        await event.message.respond("\nEl llanto...\nEs el esposo de la llanta")

@bot.listen()
async def pene(event: hikari.GuildMessageCreateEvent) -> None:
    if event.is_bot or not event.content:
        return

    if event.content.startswith("pene"):
        await event.message.respond("comes ajajajaja")


@bot.listen()
async def oscar(event: hikari.GuildMessageCreateEvent) -> None:
    if event.is_bot or not event.content:
        return

    if event.content.startswith("Oscar Meza"):
        await event.message.respond("me lleva la berga")


@bot.command
@lightbulb.option('num2','Dame un número: ',type=int)
@lightbulb.option('num1','Dame otro número: ',type=int)
@lightbulb.command('suma','Ps sumo we')
@lightbulb.implements(lightbulb.SlashCommand)
async def suma(ctx):
    await ctx.respond(ctx.options.num1+ctx.options.num2)


bot.run()



