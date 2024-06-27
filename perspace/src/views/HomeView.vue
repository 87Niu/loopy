<template>
    <ContentBase
        ><div class="home">
            <header class="header">
                <h1>Welcome to Our Website</h1>
                <p>Discover Amazing Content</p>
            </header>
            <main class="main">
                <section class="features">
                    <div class="feature">
                        <i class="fas fa-book"></i>
                        <h2>Read Articles</h2>
                        <p>
                            Explore a wide range of articles on various topics.
                        </p>
                    </div>
                    <div class="feature">
                        <i class="fas fa-image"></i>
                        <h2>View Images</h2>
                        <p>Enjoy stunning images from around the world.</p>
                    </div>
                    <div class="feature">
                        <i class="fas fa-video"></i>
                        <h2>Watch Videos</h2>
                        <p>Watch entertaining and informative videos.</p>
                    </div>
                </section>
                <section class="cta">
                    <h2>Sign Up Now!</h2>
                    <p>Join our community and start exploring.</p>
                    <button class="btn">Sign Up</button>
                </section>
            </main>
            <footer class="footer">
                <p>&copy; 2024 Your Website. All rights reserved.</p>
            </footer>
        </div></ContentBase
    >
</template>

<script>
import ContentBase from "../components/ContentBase.vue";

export default {
    name: "HomeView",
    components: {
        ContentBase,
    },
};
</script>

<style scoped>
.home {
    text-align: center;
}

.header {
    background-color: #333;
    color: #fff;
    padding: 40px 0;
}

.header h1 {
    font-size: 2.5rem;
}

.main {
    padding: 40px 0;
}

.features {
    display: flex;
    justify-content: space-around;
    margin-bottom: 40px;
}

.feature {
    flex: 1;
    padding: 20px;
}

.feature i {
    font-size: 3rem;
    margin-bottom: 20px;
}

.cta {
    background-color: #f4f4f4;
    padding: 40px 0;
}

.cta h2 {
    font-size: 2rem;
    margin-bottom: 20px;
}

.btn {
    background-color: #333;
    color: #fff;
    padding: 10px 20px;
    border: none;
    border-radius: 5px;
    font-size: 1rem;
    cursor: pointer;
    transition: background-color 0.3s ease;
}

.btn:hover {
    background-color: #555;
}

.footer {
    background-color: #333;
    color: #fff;
    padding: 20px 0;
}
</style>
