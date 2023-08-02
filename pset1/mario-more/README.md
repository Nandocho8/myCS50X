<body class="">

<main class="col-lg" style="margin-bottom: 870px; margin-top: 58px;">
<h1>Mario</h1>

<h2>World 1-1</h2>

<p>Toward the beginning of World 1-1 in Nintendo’s Super Mario Brothers, Mario must hop over adjacent pyramids of blocks, per the below.</p>

<p><img src="pyramids.png" alt="screenshot of Mario jumping over adjacent pyramids"></p>

<p>Let’s recreate those pyramids in C, albeit in text, using hashes (<code class="language-plaintext highlighter-rouge">#</code>) for bricks, a la the below. Each hash is a bit taller than it is wide, so the pyramids themselves will also be taller than they are wide.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>   #  #
  ##  ##
 ###  ###
####  ####
</code></pre></div></div>

<p>The program we’ll write will be called <code class="language-plaintext highlighter-rouge">mario</code>. And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.</p>

<p>Here’s how the program might work if the user inputs <code class="language-plaintext highlighter-rouge">8</code> when prompted:</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./mario
Height: 8
       #  #
      ##  ##
     ###  ###
    ####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########

</code></pre></div></div>

<p>Here’s how the program might work if the user inputs <code class="language-plaintext highlighter-rouge">4</code> when prompted:</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./mario
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
</code></pre></div></div>

<p>Here’s how the program might work if the user inputs <code class="language-plaintext highlighter-rouge">2</code> when prompted:</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./mario
Height: 2
 #  #
##  ##
</code></pre></div></div>

<p>And here’s how the program might work if the user inputs <code class="language-plaintext highlighter-rouge">1</code> when prompted:</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./mario
Height: 1
#  #
</code></pre></div></div>

<p>If the user doesn’t, in fact, input a positive integer between 1 and 8, inclusive, when prompted, the program should re-prompt the user until they cooperate:</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./mario
Height: -1
Height: 0
Height: 42
Height: 50
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
</code></pre></div></div>

<p>Notice that width of the “gap” between adjacent pyramids is equal to the width of two hashes, irrespective of the pyramids’ heights.</p>

<p>Open your <code class="language-plaintext highlighter-rouge">mario.c</code> file to implement this problem as described!</p>

<h3>Walkthrough</h3>

<div class="ratio ratio-16x9" data-video=""><iframe allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen="" class="border" data-video="" src="https://www.youtube.com/embed/FzN9RAjYG_Q?modestbranding=0&amp;rel=0&amp;showinfo=0" scrolling="no" id="iFrameResizer0" style="overflow: hidden;"></iframe></div>

<h3>How to Test Your Code</h3>

<p>Does your code work as prescribed when you input</p>

<ul class="fa-ul">
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span><code class="language-plaintext highlighter-rouge">-1</code> (or other negative numbers)?</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span><code class="language-plaintext highlighter-rouge">0</code>?</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span><code class="language-plaintext highlighter-rouge">1</code> through <code class="language-plaintext highlighter-rouge">8</code>?</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span><code class="language-plaintext highlighter-rouge">9</code> or other positive numbers?</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>letters or words?</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>no input at all, when you only hit Enter?</li>
</ul>

## Results

![Alt text](image.png)

</body>